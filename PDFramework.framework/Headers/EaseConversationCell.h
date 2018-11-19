/************************************************************
 *  * Hyphenate CONFIDENTIAL
 * __________________
 * Copyright (C) 2016 Hyphenate Inc. All rights reserved.
 *
 * NOTICE: All information contained herein is, and remains
 * the property of Hyphenate Inc.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Hyphenate Inc.
 */

#import <UIKit/UIKit.h>

#import "IConversationModel.h"
#import "IModelCell.h"
#import "EaseImageView.h"
#import "TagView.h"

#import "BaseChatlistView.h"

@protocol EaseConversationCellDelegate <NSObject>

-(void)accessListToUserListCallBack:(NSDictionary *)userInfo model:(id<IConversationModel>)model;

@end

/** @brief cell的最小高度 */
static CGFloat EaseConversationCellMinHeight = 72.0f;

/** @brief 会话列表自定义UITableViewCell */

@interface EaseConversationCell : UITableViewCell<IModelCell>

@property(weak,nonatomic)id<EaseConversationCellDelegate> delegate;

/** @brief 头像(用户、群组、聊天室) */
@property (strong, nonatomic) EaseImageView *avatarView;

/** @brief 最近一条消息的信息 */
@property (strong, nonatomic) UILabel *detailLabel;

/** @brief 时间 */
@property (strong, nonatomic) UILabel *timeLabel;

/** @brief 会话标题 */
@property (strong, nonatomic) UILabel *titleLabel;

/** @brief 会话对象 */
@property (strong, nonatomic) id<IConversationModel> model;

/** @brief 是否显示头像，默认为YES */
@property (nonatomic) BOOL showAvatar;

/** @brief title的字体 */
@property (nonatomic) UIFont *titleLabelFont UI_APPEARANCE_SELECTOR;

/** @brief title文字颜色 */
@property (nonatomic) UIColor *titleLabelColor UI_APPEARANCE_SELECTOR;

/** @brief 最近一条消息字体 */
@property (nonatomic) UIFont *detailLabelFont UI_APPEARANCE_SELECTOR;

/** @brief 最近一条消息文字颜色 */
@property (nonatomic) UIColor *detailLabelColor UI_APPEARANCE_SELECTOR;

/** @brief 时间文字字体 */
@property (nonatomic) UIFont *timeLabelFont UI_APPEARANCE_SELECTOR;

/** @brief 时间文字颜色 */
@property (nonatomic) UIColor *timeLabelColor UI_APPEARANCE_SELECTOR;



/**
 转接标签
 */
@property(strong,nonatomic) UIButton *transferLab;

/**
 标签
 */
@property (strong, nonatomic) TagView *tagView;

/**
 用户信息
 */
@property(strong,nonatomic)NSDictionary *userInfo;

/**
 类型
 */
@property(assign,nonatomic)Conversation conversationType;

/**
 聊天激活
 */
@property(strong,nonatomic)UIButton *chatButton;

@end
