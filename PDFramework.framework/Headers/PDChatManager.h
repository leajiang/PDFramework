//
//  PDChatManager.h
//  PDChat
//
//  Created by PeiDou on 2018/11/20.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 *  \~chinese
 *  网络连接状态
 *
 *  \~english
 *  Network Connection Status
 */
typedef enum {
    PDConnectionConnected = 0,  /*! *\~chinese 已连接 *\~english Connected */
    PDConnectionDisconnected,   /*! *\~chinese 未连接 *\~english Disconnected */
} PDConnectionState;

@protocol PDChatManagerDelegate <NSObject>

@optional

/*!
 *  \~chinese
 *  SDK连接服务器的状态变化时会接收到该回调
 *
 *  有以下几种情况, 会引起该方法的调用:
 *  1. 登录成功后, 手机无法上网时, 会调用该回调
 *  2. 登录成功后, 网络状态变化时, 会调用该回调
 *
 *  @param aConnectionState 当前状态
 *
 *  \~english
 *  Invoked when server connection state has changed
 *
 *  @param aConnectionState Current state
 */
- (void)connectionStateDidChange:(PDConnectionState)aConnectionState;

/*!
 *  \~chinese
 *  自动登录完成时的回调
 *
 *  @param aError 错误信息
 *
 *  \~english
 *  Invoked when auto login is completed
 *
 *  @param aError Error
 */
- (void)autoLoginDidCompleteWithError:(NSString *)aError;

/*!
 *  \~chinese
 *  当前登录账号在其它设备登录时会接收到此回调
 *
 *  \~english
 *  Invoked when current IM account logged into another device
 */
- (void)userAccountDidLoginFromOtherDevice;

/*!
 *  \~chinese
 *  当前登录账号已经被从服务器端删除时会收到该回调
 *
 *  \~english
 *  Invoked when current IM account is removed from server
 */
- (void)userAccountDidRemoveFromServer;

/*!
 *  \~chinese
 *  服务被禁用
 *
 *  \~english
 *  Delegate method will be invoked when User is forbidden
 */
- (void)userDidForbidByServer;

/*!
 *  \~chinese
 *  当前登录账号被强制退出时会收到该回调，有以下原因：
 *    1.密码被修改；
 *    2.登陆设备数过多；
 *
 *  \~english
 *  Delegate method will be invoked when current IM account is forced to logout with the following reasons:
 *    1. The password is modified
 *    2. Logged in too many devices
 */
- (void)userAccountDidForcedToLogout:(NSString *)aError;

@end

@interface PDChatManager : NSObject

/**
 初始化SDK
 */
+ (void)initializePDChatSDKDelegate:(id<PDChatManagerDelegate>)adelegate delegateQueue:(dispatch_queue_t)aQueue;

/**
 是否显示日志

 @param iFlag 标记 默认NO
 */
+ (void)isShowLog:(BOOL)iFlag;

/**
 客服端登录接口

 @param userName 当前用户名（必填）
 @param tenantId 当前用户ID（必填）
 @param headUrl 当前用户头像（选填）
 @param asuccess 成功回调
 @param aerror 失败回调
 */
+ (void)pdLoginWithUsername:(NSString *)userName
           withUserTenantId:(NSString *)tenantId
            withUserHeadUrl:(NSString *)headUrl
               successBlock:(void(^)(void))asuccess
                 errorBlock:(void(^)(NSString *string))aerror;


/**
 进入聊天列表接口(必须先登录)

 @param controller 当前视图控制器（必填）
 */
+ (void)pdIntoConsultOnlineViewcontroller:(UIViewController *)controller;

/**
 获取当前客服未读消息条数(必须先登录)
 */
+ (NSInteger)pdChatUnreadmessageCount;

/**
 退出SDK
 */
+ (void)userLogoutPDClient;



/**
 测试使用（请勿用）

 @param hxAccount <#hxAccount description#>
 @param hxPwd <#hxPwd description#>
 @param tenantId <#tenantId description#>
 @param asuccess <#asuccess description#>
 @param pderror <#pderror description#>
 */
+ (void)testpdLoginWithhxAccount:(NSString *)hxAccount
                       withhxPwd:(NSString *)hxPwd
                withUserTenantId:(NSString *)tenantId
                    successBlock:(void(^)(void))asuccess
                      errorBlock:(void(^)(NSString *string))pderror;

@end
