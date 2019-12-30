sdphost.exe -u 0x1fc9,0x0135 -- write-file 0x20000000 ivt_flashloader.bin
SDPHOST -u 0x1fc9,0x0135 -- jump-address 0x20000400
choice /t 1 /d y /n >nul
blhost -u -- fill-memory 0x2000 0x04 0xc0000007 
blhost -u -- configure-memory 0x09 0x2000 
blhost -u -t 40000 -- flash-erase-region 0x70000000 0x300000
blhost -u -- write-memory 0x70000000 test.bin
choice /t 1 /d y /n >nul
pause