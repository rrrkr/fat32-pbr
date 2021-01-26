#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<unistd.h>
#include"pbr.h"

int main(void)
{
	Fat32_Pbr pbr;
	int fd;
	int i;
	ssize_t cc;
	if((fd = open("out",O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}
	cc = read(fd,&pbr,sizeof(pbr));
	
	printf("BS_jmpBoot = ");
	for(i = 0;i < sizeof(pbr.bs_jmpboot);i++)
			printf("%x ",pbr.bs_jmpboot[i]);
	putchar('\n');
	printf("BS_OEMName = %s\n",pbr.bs_oemname);
	printf("BPB_BytsPerSec = %d\n",pbr.bpb.bytspersec);
	printf("BPB_SecPerClus = %d\n",pbr.bpb.secperclus);
	printf("BPB_RsvdSecCnt = %d\n",pbr.bpb.rsvdseccnt);
	printf("BPB_NumFATs = %d\n",pbr.bpb.numfats);
	printf("BPB_RootEntCnt = %d\n",pbr.bpb.rootentcnt);
	printf("BPB_TotSec16 = %d\n",pbr.bpb.totsec16);
	printf("BPB_Media = %d\n",pbr.bpb.media);
	printf("BPB_FATSz16 = %d\n",pbr.bpb.fatsz16);
	printf("BPB_SecPerTrk = %d\n",pbr.bpb.secpertrk);
	printf("BPB_NumHeads = %d\n",pbr.bpb.numheads);
	printf("BPB_HiddSec = %d\n",pbr.bpb.hiddsec);
	printf("BPB_TotSec32 = %d\n",pbr.bpb.totsec32);
	printf("BPB_DrvNum = %d\n",pbr.bs_drvnum);
	printf("BPB_Reserved1 = %d\n",pbr.bs_reserved1);
	printf("BPB_BootSig = %d\n",pbr.bs_bootsig);
	printf("BPB_VolID = %x\n",pbr.bs_volid);
	printf("BPB_VolLab = %s\n",pbr.bs_vollab);
	printf("BPB_FilSysType = %s\n",pbr.bs_filsystype);
	printf("sizeof pdr = %d\n",sizeof(pbr));
	printf("read size = %d\n",sizeof(pbr.bs_oemname));
	close(fd);
	return 0;
}
