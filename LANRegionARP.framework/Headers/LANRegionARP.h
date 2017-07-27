//
//  LANRegionARP.h
//  LANDeviceScan
//
//  Created by YLCHUN on 2017/7/26.
//  Copyright © 2017年 ylchun. All rights reserved.
//
//  获取设备信息通过访问 https://www.macvendorlookup.com/oui.php?mac=[Mac地址]
//

#import <Foundation/Foundation.h>
#import "LANRegion.h"

@interface ARPInfo : NSObject
@property (nonatomic, readonly) NSString *ipAddr;//ip地址
@property (nonatomic, readonly) NSString *macAddr;//mac地址
@property (nonatomic, readonly) BOOL isLocal;//本地地址
@property (nonatomic, readonly) BOOL isGateway;//网关地址
@end

@interface LANRegionARP : NSObject

@property (nonatomic, readonly) BOOL arping;//YES 正在获取arp信息

/**
 获取arp单例

 @return <#return value description#>
 */
+ (instancetype)share;

/**
 清除arp单例，正在获取arp信息时不可清理

 @return 清除结果
 */
+ (BOOL)clear;

/**
 获取arp信息

 @param infos infos ARPInfo数组
 @return YES 成功，NO失败
 */
-(BOOL)arpInfos:(void(^)(LANRegion *lanRegion, NSArray<ARPInfo*> *infos))infos;

@end
