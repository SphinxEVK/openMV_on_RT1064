1.由于openmv源码较多，因此编译时间比较长，如果不需要查看或者修改源码的可以直接使用本工程，打开工程后不用编译直接点击下载按钮将程序下载到单片机即可使用

2.硬件环境：
凌瞳摄像头+RT1064核心板
a.RT1064的J1 和 J3 分别短接
b.摄像头直接与核心板的CSI接口连接
c.TF卡插入核心板的TF卡槽
d.使用typeC数据线将核心板与电脑连即可
e.TF卡推荐使用Class10

3.软件摄像头功能：
reset 			摄像头复位
sleep			摄像头睡眠
set_pixformat		设置像素格式仅支持设置为RGB565和YUV422
set_framesize		设置图像大小，仅支持QQVGA、HQVGA、QVGA、VGA
set_framerate		设置图像帧率，仅支持设置为3、8、15、30、60，图像默认为50帧
set_brightness		设置图像亮，手动曝光模式时可设置范围：0-65535 推荐800  	自动曝光模式时可设置范围：0-255  推荐100
set_auto_exposure		设置自动曝光，0：手动曝光模式   1：自动曝光模式
get_exposure_us		获取曝光值，需要注意这里返回的值单位并不是us，仅仅是在使用set_brightness函数时所设置的数值，数值仅仅代表越大曝光时间越长，图像也就越亮
set_auto_whitebal		设置自动白平衡0：手动白平衡  1：自动白平衡
set_hmirror		设置图像左右镜像	0：不镜像	1：左右镜像
set_vflip			设置图像上下镜像	0：不镜像	1：上下镜像

sensor其他功能并未实现，例如set_contrast、set_saturation、set_gainceiling、set_colorbar、set_auto_gain、get_gain_db等等，
如果调用相关函数，不会有任何的作用，且不会返回错误提示.