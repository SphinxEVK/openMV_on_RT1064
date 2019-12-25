### 1.关于openMV on RT1064

​	if（camera == lingtong && mcu == RT1064)
 	 OpenMV_start；

​	闲着也是闲着，openMV还能这么玩，最近面试完拿着学弟买的逐飞家新摄像头+RT1064捣鼓了一下openMV，做个开源，留给大家玩；话说逐飞的这颗sensor找不到手册，捣鼓期间找了逐飞帮忙适配摄像头部分，谢谢他们的技术支持，但是用逐飞家平台也算广告啦，鸡腿我就不要了，群主你看到了去github给我点星星就行了，哈哈。

​	由于openmv源码较多，因此编译时间比较长，如果不需要查看或者修改源码的可以直接使用本工程，打开工程后不用编译直接点击下载按钮将程序下载到单片机即可使用。

​	*注：当前暂只发编译好，稳定的版本（无源码），待到一些新的feature落地之后，再放出来，因为可以直接使用microPython进行二次开发，所以源码再等等也不迟。

### 2.硬件环境：

​	基于CM7架构的最强MCU，除了ST的H7系列，还有NXP推出的RT10xx系列的MCU，我们想做的就是能够保证足够的运算资源的同时，还能在性价比上能够得到提升，那这一点非RT1064莫属。**在这里，我首先要感谢开源社区的大佬们先前的努力，让我们的项目计划得以平稳推进。**

​	根据我们之前使用的openMV设备看，我们有针对性的改善了摄像头的性能（硬件上），其实手上的选择并不多，但要权衡一款具备性价比的摄像头，同时拥有不错的本底素质，那么9V03x的这颗sensor就要让步了。所以就**白嫖**来学弟的逐飞套件了，在调试过程中，也充分得到了逐飞的技术支持，总的来说技术支持不是盖的，哈哈（再说下去就有打广告之嫌了）所以本DEMO的调试硬件特点如下：

```
凌瞳摄像头+RT1064核心板
a.RT1064的J1 和 J3 分别短接
b.摄像头直接与核心板的CSI接口连接
c.TF卡插入核心板的TF卡槽
d.使用typeC数据线将核心板与电脑连即可
e.TF卡推荐使用Class10
```

​	感兴趣的同学可以上手这套硬件，这也是暂时不用我们自己折腾的那套硬件的原因之一，大家能够很容易地找到更具性价比的配套硬件，同时还能兼容传统的调车扩展能力，其实就很好了。

### 3.软件摄像头功能：

​	以下列出了这颗摄像头目前我们所提供的方法：

```
reset 			摄像头复位
sleep			摄像头睡眠
set_pixformat		设置像素格式仅支持设置为RGB565和YUV422
set_framesize		设置图像大小，仅支持QQVGA、HQVGA、QVGA、VGA
set_framerate		设置图像帧率，仅支持设置为3、8、15、30、60，图像默认为50帧
set_brightness		设置图像亮，手动曝光模式时可设置范围：0-65535 推荐800  	自动曝光模式时可设置范围：0-255  推荐100
set_auto_exposure	设置自动曝光，0：手动曝光模式   1：自动曝光模式
get_exposure_us		获取曝光值，需要注意这里返回的值单位并不是us，仅仅是在使用set_brightness 	函数时所设置的数值，数值仅仅代表越大曝光时间越长，图像也就越亮
set_auto_whitebal		设置自动白平衡0：手动白平衡  1：自动白平衡
set_hmirror		设置图像左右镜像	0：不镜像	1：左右镜像
set_vflip		设置图像上下镜像	0：不镜像	1：上下镜像
```

### 4.尚未实现部分声明：

​	需要注意，部分方法暂时没用上，所以先鸽一段时间。

```
sensor其他功能并未实现，例如set_contrast、set_saturation、set_gainceiling、set_colorbar、set_auto_gain、get_gain_db等等，如果调用相关函数，不会有任何的作用，且不会返回错误提示.请务必注意！
```

### 5.实际演示：
![figure1](https://github.com/SphinxEVK/openMV_on_RT1064/blob/master/figures/%E4%BA%8C%E7%BB%B4%E7%A0%81%E8%AF%86%E5%88%AB.jpg)


![figure2](https://github.com/SphinxEVK/openMV_on_RT1064/blob/master/figures/%E9%A2%9C%E8%89%B2%E8%AF%86%E5%88%AB.jpg)

### 6.新增使用USB方式下载固件的脚本：
使用原厂提供的flashloader功能，可以通过USB进行对固件的直接烧录，使用详情请见[program_tool](https://github.com/SphinxEVK/openMV_on_RT1064/blob/master/program_tool)。此方式的优点是不借助其他调试/烧录工具进行MCU的烧写，但功能只限于烧写/擦除，不具备绑定IDE调试的功能。
