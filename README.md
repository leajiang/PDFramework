# PDFramework

使用说明：
使用Pod集成
在Podfile加入pod 'PDFramework','~>3.5.1'即可使用

1.使用时请导入库头文件#import <PDFramework/PDFramework.h>
2.添加初始化方法已经回调[PDChatManager initializePDChatSDKDelegate:nil delegateQueue:nil];
3.使用PDChatManager静态方法

/**
客服端登录接口

@param controller 当前视图控制器（必填）
@param userName 当前用户名（必填）
@param tenantId 当前用户ID（必填）
@param headUrl 当前用户头像（选填）
*/
+ (void)pdLoginConsultOnlineViewcontroller:(UIViewController *)controller withUserName:(NSString *)userName withUserTenantId:(NSString *)tenantId withUserHeadUrl:(NSString *)headUrl successBlock:(void(^)(void))asuccess errorBlock:(void(^)(NSString *string))aerror;


注意：退出应用时请调用+ (void)userLogoutPDClient;
具体请查看PDChatManager.h头文件



