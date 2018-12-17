//
//  ViewController.m
//  PDFrameworkDemo
//
//  Created by PeiDou on 2018/12/5.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import "ViewController.h"
#import <PDFramework/PDFramework.h>
@interface ViewController ()<PDChatManagerDelegate>
@property (weak, nonatomic) IBOutlet UITextField *userTf;
@property (weak, nonatomic) IBOutlet UITextField *pwdTf;
@property (weak, nonatomic) IBOutlet UILabel *connectStatusLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [PDChatManager initializePDChatSDKDelegate:self delegateQueue:nil];
    [PDChatManager isShowLog:YES];
    
    self.userTf.text = @"miaomiao";
    self.pwdTf.text = @"171";
    // Do any additional setup after loading the view, typically from a nib.
}
-(BOOL)userWithPwdLogic{
    
    if (self.userTf.text.length>0 && self.pwdTf.text.length>0) {
        return YES;
    }
    return NO;
}

- (IBAction)login:(id)sender {
    if (![self userWithPwdLogic]) {
        
        return;
    }
    [PDChatManager pdLoginWithUsername:self.userTf.text withUserTenantId:self.pwdTf.text successBlock:^{
        
        self.connectStatusLabel.text = @"连接成功";
        
    } errorBlock:^(NSString *string) {
        
        self.connectStatusLabel.text = string;
    }];
}

- (IBAction)logout:(id)sender {
    [PDChatManager userLogoutPDClient];
    self.connectStatusLabel.text = @"未连接";
}

- (IBAction)intoChatList:(id)sender {
     [PDChatManager pdIntoConsultOnlineViewcontroller:self];
}

- (IBAction)getunreadcount:(id)sender {
    NSInteger count = [PDChatManager pdChatUnreadmessageCount];
    NSLog(@"%ld",count);
}
#pragma mark - PDChatManagerDelegate
- (void)userAccountDidLoginFromOtherDevice{
    self.connectStatusLabel.text = @"已被其他设备登录！！！";
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
