#!/usr/bin/env python3
"""Create/verify BPS1 delta patches (no ROM bundled).
Format: https://floating.muncher.se/byuu/bps/bps_spec.html
Uses SourceRead, TargetRead, SourceCopy; accepts all four BPS actions.
"""
import argparse,pathlib,struct,zlib

def number(value):
    out=bytearray()
    while True:
        byte=value&127; value>>=7
        if not value:
            out.append(byte|128); return out
        out.append(byte); value-=1

def create(source,target):
    meta=b'Wishes Japanese work in progress; not a complete localization'
    out=bytearray(b'BPS1')+number(len(source))+number(len(target))+number(len(meta))+meta
    anchors={}
    for pos in range(0,len(source)-32,256): anchors.setdefault(source[pos:pos+32],pos)
    i=0; relative=0; literals=bytearray()
    def flush():
        if literals:
            out.extend(number(((len(literals)-1)<<2)|1)); out.extend(literals); literals.clear()
    while i<len(target):
        same=i+32<=len(source) and source[i:i+32]==target[i:i+32]
        pos=i if same else anchors.get(target[i:i+32])
        if pos is None:
            literals.append(target[i]); i+=1; continue
        size=0; maximum=min(len(source)-pos,len(target)-i)
        while size+4096<=maximum and source[pos+size:pos+size+4096]==target[i+size:i+size+4096]: size+=4096
        while size<maximum and source[pos+size]==target[i+size]: size+=1
        if size<32:
            literals.append(target[i]); i+=1; continue
        flush(); out.extend(number(((size-1)<<2)|(0 if same else 2)))
        if not same:
            delta=pos-relative; out.extend(number((abs(delta)<<1)|(delta<0))); relative=pos+size
        i+=size
    flush()
    out.extend(struct.pack('<II',zlib.crc32(source),zlib.crc32(target)))
    out.extend(struct.pack('<I',zlib.crc32(out)))
    return bytes(out)

def apply(source,patch):
    if patch[:4]!=b'BPS1' or zlib.crc32(patch[:-4])!=struct.unpack('<I',patch[-4:])[0]: raise ValueError('patch CRC/header')
    p=4
    def read():
        nonlocal p
        result=0; shift=1
        while p<len(patch)-12:
            byte=patch[p]; p+=1; result+=(byte&127)*shift
            if byte&128: return result
            shift<<=7; result+=shift
        raise ValueError('truncated integer')
    source_size=read(); target_size=read(); metadata_size=read(); p+=metadata_size
    if source_size!=len(source) or zlib.crc32(source)!=struct.unpack('<I',patch[-12:-8])[0]: raise ValueError('source CRC/size')
    out=bytearray(); sr=0; tr=0
    while p<len(patch)-12:
        action=read(); size=(action>>2)+1; kind=action&3
        if kind==0: out.extend(source[len(out):len(out)+size])
        elif kind==1: out.extend(patch[p:p+size]); p+=size
        else:
            offset=read(); delta=-(offset>>1) if offset&1 else offset>>1
            if kind==2:
                sr+=delta
                if sr<0 or sr+size>len(source): raise ValueError('source copy bounds')
                out.extend(source[sr:sr+size]); sr+=size
            else:
                tr+=delta
                for _ in range(size):
                    if tr<0 or tr>=len(out): raise ValueError('target copy bounds')
                    out.append(out[tr]); tr+=1
        if len(out)>target_size: raise ValueError('output bounds')
    if len(out)!=target_size or zlib.crc32(out)!=struct.unpack('<I',patch[-8:-4])[0]: raise ValueError('target CRC/size')
    return bytes(out)

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__); ap.add_argument('source',type=pathlib.Path); ap.add_argument('target',type=pathlib.Path); ap.add_argument('patch',type=pathlib.Path); args=ap.parse_args()
    source=args.source.read_bytes(); target=args.target.read_bytes(); patch=create(source,target)
    if apply(source,patch)!=target: raise ValueError('round-trip mismatch')
    args.patch.write_bytes(patch); print('Verified BPS round trip:',len(patch),'bytes')
