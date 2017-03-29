
#pragma mark - 平台
目标平台： iOS Android 开发平台： macOS Linux Windows


#pragma mark - 环境搭建：
iOS 安装Xcode

android ：目前需要Android Studio2.0或更高版本。

    下载地址 http://www.android-studio.org/
    Android Studio需要Java Development Kit [JDK] 1.8或更高版本。可以在命令行中输入 javac -version来查看你当前安装的JDK版本。如果版本不合要求，则可以到 官网上下载。
    Android Studio包含了运行和测试React Native应用所需的Android SDK和模拟器。

    除非特别注明，请不要改动安装过程中的选项。比如Android Studio默认安装了 Android Support Repository，而这也是React Native必须的（否则在react-native run-android时会报appcompat-v7包找不到的错误）。

#pragma mark - 创建项目：
react-native init 项目名字  //执行完后 会在当前目录创建项目 所以要提前cd 到目标目录 然后再创建项目

cd 项目名字 //到项目目录下

react-native run-ios  //执行iOS项目   run-android 执行安卓项目

#pragma mark - 运行项目：
//安卓
在终端下运行adb logcat *:S ReactNative:V ReactNativeJS:V可以看到你的应用的日志

