调试


#pragma mark - 访问App内的开发菜单
你可以通过摇晃设备或是选择iOS模拟器的"Hardware"菜单中的"Shake Gesture"选项来打开开发菜单。另外，如果是在iOS模拟器中运行，还可以按下Command⌘ + D 快捷键，Android模拟器对应的则是Command⌘ + M（windows上可能是F1或者F2）。



注意：在成品（release/producation builds）中开发者菜单会被关闭。
#pragma mark - 刷新JavaScript
传统的原生应用开发中，每一次修改都需要重新编译，但在RN中你只需要刷新一下JavaScript代码，就能立刻看到变化。具体的操作就是在开发菜单中点击"Reload"选项。也可以在iOS模拟器中按下Command⌘ + R ，Android模拟器上对应的则是按两下R。（注意，某些RN版本可能在windows中reload无效，请等待官方修复）

如果在iOS模拟器中按下Command⌘ + R没啥感觉，则注意检查Hardware菜单中，Keyboard选项下的"Connect Hardware Keyboard"是否被选中。
#pragma mark - 自动刷新
选择开发菜单中的"Enable Live Reload"可以开启自动刷新，这样可以节省你开发中的时间。

更神奇的是，你还可以保持应用的当前运行状态，修改后的JavaScript文件会自动注入进来（就好比行驶中的汽车不用停下就能更换新的轮胎）。要实现这一特性只需开启开发菜单中的Hot Reloading选项。

某些情况下hot reload并不能顺利实施。如果碰到任何界面刷新上的问题，请尝试手动完全刷新。
但有些时候你必须要重新编译应用才能使修改生效：

增加了新的资源(比如给iOS的Images.xcassets或是Andorid的res/drawable文件夹添加了图片)
更改了任何的原生代码（objective-c/swift/java）
应用内的错误与警告提示（红屏和黄屏）
红屏或黄屏提示都只会在开发版本中显示，正式的离线包中是不会显示的。

#pragma mark - 红屏错误
应用内的报错会以全屏红色显示在应用中（调试模式下），我们称为红屏（red box）报错。你可以使用console.error()来手动触发红屏错误。

#pragma mark - 黄屏警告
应用内的警告会以全屏黄色显示在应用中（调试模式下），我们称为黄屏（yellow box）报错。点击警告可以查看详情或是忽略掉。 和红屏报警类似，你可以使用console.warn()来手动触发黄屏警告。 在默认情况下，开发模式中启用了黄屏警告。可以通过以下代码关闭：

console.disableYellowBox = true;
console.warn('YellowBox is disabled.');
你也可以通过代码屏蔽指定的警告，像下面这样设置一个数组：

console.ignoredYellowBox = ['Warning: ...'];
数组中的字符串就是要屏蔽的警告的开头的内容。（例如上面的代码会屏蔽掉所有以Warning开头的警告内容）

红屏和黄屏在发布版（release/production）中都是自动禁用的。
#pragma mark - 访问控制台日志
在运行RN应用时，可以在终端中运行如下命令来查看控制台的日志：

$ react-native log-ios
$ react-native log-android
此外，你也可以在iOS模拟器的菜单中选择Debug → Open System Log...来查看。如果是Android应用，无论是运行在模拟器或是真机上，都可以通过在终端命令行里运行adb logcat *:S ReactNative:V ReactNativeJS:V命令来查看。

#pragma mark - Chrome开发者工具
在开发者菜单中选择"Debug JS Remotely"选项，即可以开始在Chrome中调试JavaScript代码。点击这个选项的同时会自动打开调试页面 http://localhost:8081/debugger-ui.

在Chrome的菜单中选择Tools → Developer Tools可以打开开发者工具，也可以通过键盘快捷键来打开（Mac上是Command⌘ + Option⌥ + I，Windows上是Ctrl + Shift + I或是F12）。打开有异常时暂停（Pause On Caught Exceptions）选项，能够获得更好的开发体验。

译注：Chrome中并不能直接看到App的用户界面，而只能提供console的输出，以及在sources项中断点调试js脚本。

目前无法正常使用React开发插件（就是某些教程或截图上提到的Chrome开发工具上多出来的React选项），但这并不影响代码的调试。如果你需要像调试web页面那样查看RN应用的jsx结构，暂时只能使用Nuclide的"React Native Inspector"这一功能来代替。
使用Chrome开发者工具来在设备上调试
对于iOS真机来说，需要打开 RCTWebSocketExecutor.m文件，然后将其中的"localhost"改为你的电脑的IP地址，最后启用开发者菜单中的"Debug JS Remotely"选项。

对于Android 5.0+设备（包括模拟器）来说，将设备通过USB连接到电脑上后，可以使用adb命令行工具来设定从设备到电脑的端口转发：

adb reverse tcp:8081 tcp:8081

如果设备Android版本在5.0以下，则可以在开发者菜单中选择"Dev Settings - Debug server host for device"，然后在其中填入电脑的”IP地址:端口“。

如果在Chrome调试时遇到一些问题，那有可能是某些Chrome的插件引起的。试着禁用所有的插件，然后逐个启用，以确定是否某个插件影响到了调试。
#pragma mark - 使用自定义的JavaScript调试器来调试
如果想用其他的JavaScript调试器来代替Chrome，可以设置一个名为REACT_DEBUGGER的环境变量，其值为启动自定义调试器的命令。调试的流程依然是从开发者菜单中的"Debug JS Remotely"选项开始。

被指定的调试器需要知道项目所在的目录（可以一次传递多个目录参数，以空格隔开）。例如，如果你设定了REACT_DEBUGGER="node /某个路径/launchDebugger.js --port 2345 --type ReactNative"，那么启动调试器的命令就应该是node /某个路径/launchDebugger.js --port 2345 --type ReactNative /某个路径/你的RN项目目录。

以这种方式执行的调试器最好是一个短进程（short-lived processes），同时最好也不要有超过200k的文字输出。
#pragma mark - 在Android上使用Stetho来调试
在android/app/build.gradle文件中添加：

compile 'com.facebook.stetho:stetho:1.3.1'
compile 'com.facebook.stetho:stetho-okhttp3:1.3.1'
在android/app/src/main/java/com/{yourAppName}/MainApplication.java文件中添加：

import com.facebook.react.modules.network.ReactCookieJarContainer;
import com.facebook.stetho.Stetho;
import okhttp3.OkHttpClient;
import com.facebook.react.modules.network.OkHttpClientProvider;
import com.facebook.stetho.okhttp3.StethoInterceptor;
import java.util.concurrent.TimeUnit;
在android/app/src/main/java/com/{yourAppName}/MainApplication.java文件中添加：

public void onCreate() {
    super.onCreate();
    Stetho.initializeWithDefaults(this);
    OkHttpClient client = new OkHttpClient.Builder()
    .connectTimeout(0, TimeUnit.MILLISECONDS)
    .readTimeout(0, TimeUnit.MILLISECONDS)
    .writeTimeout(0, TimeUnit.MILLISECONDS)
    .cookieJar(new ReactCookieJarContainer())
    .addNetworkInterceptor(new StethoInterceptor())
    .build();
    OkHttpClientProvider.replaceOkHttpClient(client);
}
运行react-native run-android

打开一个新的Chrome选项卡，在地址栏中输入chrome://inspect并回车。在页面中选择'Inspect device' （标有"Powered by Stetho"字样）。

#pragma mark - 调试原生代码
在和原生代码打交道时（比如编写原生模块），可以直接从Android Studio或是Xcode中启动应用，并利用这些IDE的内置功能来调试（比如设置断点）。这一方面和开发原生应用并无二致。

#pragma mark - 性能监测
你可以在开发者菜单中选择"Pref Monitor"选项以开启一个悬浮层，其中会显示应用的当前帧数。
