//
//  BaseService.h
//  iosdemo
//
//  Created by vnetoo on 2017/9/20.
//  Copyright © 2017年 vnetoo. All rights reserved.
//

#import <Foundation/Foundation.h>

#define isTest

#define PD_HXACCOUNT [[NSUserDefaults standardUserDefaults]objectForKey:@"pd_hxAccount"]  //环信账号
#define PD_USERNAME [[NSUserDefaults standardUserDefaults]objectForKey:@"pd_username"]    //客服登录名
#define PD_TENANTID [[NSUserDefaults standardUserDefaults]objectForKey:@"pd_tenantId"]    //租户id


#ifdef isTest
    //http://47.99.209.73/peidou
    //http://192.168.1.118:8081
    #define BASEAPI @"http://47.99.209.73/peidou/api/v1/"
#else
    #define BASEAPI @"http://localhost:8080/api/v1/"
#endif
/**
 客户对话列表
 */
#define USERLIST @"seats/userList"

/**
 待接入客户列表
 */
#define TOACCESSLIST @"seats/toAccessList"

//待接入转客户对话
#define ACCESSLISTTOUSERLIST    @"seats/accessListToUserList"

/**
 同事对话
 */
#define COLLEAGUELIST @"seats/colleagueList"

/**
 用户详情查询接口
 */
#define USERDETAIL  @"users/actions/userDetails"

//用户详情保存
#define SAVEUSERDETAIL  @"users/actions/updateUserInfo"

/**
 对话转接
 */
#define TEANSFERSESSION    @"users/actions/transferSession"

/**
 结束会话
 */
#define CLOSESESSION @"users/actions/closeSession"

 //查询当前租户的最大接待人数
#define SELECTMAXVISITORLIST @"user/actions/selectMaxVisitorList"

/**
 查询当前最大接待人数
 */
#define SELECTNUM @"seats/queryMaxWaitNum"

/**
 更改当前最大接待人数
 */
#define UPDATENUM @"seats/modifyMaxWaitNum"

/**
 查询标记标签
 */
#define SELECTTAG @"user/actions/selectSessionTag"
/**
 标记用户
 */
#define ACTIONTAG @"users/actions/saveSessionTag"

//转接客服列表接口
#define GETSERVICELIST @"users/actions/transferSessionToPerson"

//转接客服列表接口
#define GETSERVICEGROUPLIST @"users/actions/transferSessionToGroup"

//确认转接接口
#define CIMMITTRANSFER  @"users/actions/confirmTransferSession"

//通讯录接口
#define ADDRESSBOOKLIST @"users/actions/addressBookList"

//通讯录详细接口
#define ADDRESSBOOKLISTDETAIL @"users/actions/addressBookListDetail"

typedef void(^ServiceFinishBlock)(id result);
@interface BaseService : NSObject
+ (BaseService *)shareManager;

//test方法
-(void)getTestDataForGet:(NSString *)APIString
               parameter:(NSDictionary *)param
             finishBlock:(ServiceFinishBlock)finishBlock;

//get方法
-(void)getDataForGet:(NSString *)APIString
           parameter:(NSDictionary *)param
         finishBlock:(ServiceFinishBlock)finishBlock;
//put方法
-(void)getDataForPut:(NSString *)APIString
           parameter:(NSDictionary *)param
         finishBlock:(ServiceFinishBlock)finishBlock;

//post方法(form表单提交)
-(void)getDataForPost:(NSString *)APIString
            parameter:(NSDictionary *)param
          finishBlock:(ServiceFinishBlock)finishBlock;

//post方法(json提交)
-(void)getDataForPostbyJson:(NSString *)APIString
                  parameter:(NSDictionary *)param
                finishBlock:(ServiceFinishBlock)finishBlock;

//附带文件的post方法 文件data数据流
-(void)getDataForPostWithFile:(NSString *)APIString
                    parameter:(NSDictionary *)param
                     fileData:(NSArray *)dataArray
                  finishBlock:(ServiceFinishBlock)finishBlock;

//附带文件的post方法 文件file
-(void)getDataForPostWithFile:(NSString *)APIString
                    parameter:(NSDictionary *)param
                     filePath:(NSArray *)pathArray
                  finishBlock:(ServiceFinishBlock)finishBlock;

//下载文件 返回文件地址
-(void)creatingDownloadTask:(NSString *)APIString
                finishBlock:(ServiceFinishBlock)finishBlock;
@end
