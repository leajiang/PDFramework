# PDFramework 

客服B端使用的PDFramework

使用说明：

暂不支持手动添加请使用Pod集成

在Podfile加入pod 'PDFramework','~>1.0.9'即可使用

1.使用时请导入库头文件#import <PDFramework/PDFramework.h>

2.添加静态初始化方法以及回调

+(void)initializePDChatSDKDelegate:(id<PDChatManagerDelegate>)adelegate delegateQueue:(dispatch_queue_t)aQueue;

3.使用PDChatManager静态方法

/**
客服端登录接口

@param userName 当前租户名（必填）

@param tenantId 当前租户ID（必填）

@param headUrl 当前租户头像（选填）

*/

+(void)pdLoginWithUsername:(NSString *)userName withUserTenantId:(NSString *)tenantId withUserHeadUrl:(NSString *)headUrl successBlock:(void(^)(void))asuccess errorBlock:(void(^)(NSString *string))aerror;

4.进入聊天列表

/**
进入聊天列表接口(必须先登录)

@param controller 当前视图控制器（必填）

*/
+(void)pdIntoConsultOnlineViewcontroller:(UIViewController *)controller;


注意：退出应用时请使用+ (void)userLogoutPDClient;

具体回调和方法请查看PDChatManager.h头文件



