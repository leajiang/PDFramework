//
//  BaseChatlistView.h
//  PDChat
//
//  Created by PeiDou on 2018/10/26.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    ClientChatConversation,
    JoinChatConversation,
    MateChatConversation,
} Conversation;

@interface BaseChatlistView : UIView

@property(nonatomic,strong)NSMutableArray *userListArray;
@property(nonatomic,strong)NSMutableArray *accesslistArray;
@property(nonatomic,strong)NSMutableArray *colleaguelistArray;
/**
 类型
 */
@property(nonatomic,assign)Conversation conversationType;


-(void)tableViewDidTriggerHeaderRefresh;
/**
 获取相应的列表
 */
-(void)getUserlistFromService:(dispatch_group_t)group;

-(void)getAccesslistFromService:(dispatch_group_t)group;

-(void)getColleaguelistFromService:(dispatch_group_t)group;
@end
