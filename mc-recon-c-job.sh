#!/usr/bin/tcsh


#source /apps/root/6.10.02/setroot_CUE.csh


declair -i ang = 21

#go to the directory of build 
cd /w/hallc-scifs17exp/xem2/biswas/cross-section-code/mc-recon-c-incubator/build

make clean 
make 
./mcrecon 
