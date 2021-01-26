#ifndef _PBR_H_INCLUDED_
#define _PBR_H_INCLUDED_

typedef struct {
	unsigned char bs_jmpboot[3];
	unsigned char bs_oemname[8];
	struct{
		unsigned short bytspersec;
		unsigned char secperclus;
		unsigned short rsvdseccnt;
		unsigned char numfats;
		unsigned short rootentcnt;
		unsigned short totsec16;
		unsigned char media;
		unsigned short fatsz16;
		unsigned short secpertrk;
		unsigned short numheads;
		unsigned int hiddsec;
		unsigned int totsec32;
  }bpb;
		unsigned char bs_drvnum;
		unsigned char bs_reserved1;
		unsigned char bs_bootsig;
		unsigned int bs_volid;
		unsigned char bs_vollab[11];
		unsigned char bs_filsystype[8];
		unsigned char bs_bootcode[448];
		unsigned short bs_bootsign;
}Fat16_Pbr;

typedef struct {
	unsigned char bs_jmpboot[3];
	unsigned char bs_oemname[8];
	struct{
		unsigned short bytspersec;
		unsigned char secperclus;
		unsigned short rsvdseccnt;
		unsigned char numfats;
		unsigned short rootentcnt;
		unsigned short totsec16;
		unsigned char media;
		unsigned short fatsz16;
		unsigned short secpertrk;
		unsigned short numheads;
		unsigned int hiddsec;
		unsigned int totsec32;
		unsigned int fatsz32;
		unsigned short extflags;
		unsigned short fsver;
		unsigned int rootclus;
		unsigned short fsinfo;
		unsigned short bkbootsec;
		unsigned char reserved[12];
  }bpb;
		unsigned char bs_drvnum;
		unsigned char bs_reserved1;
		unsigned char bs_bootsig;
		unsigned int bs_volid;
		unsigned char bs_vollab[11];
		unsigned char bs_filsystype[8];
		unsigned char bs_bootcode[420];
		unsigned short bs_bootsign;
}Fat32_Pbr;

#endif
