//
//  LANRegion.h
//  LANDeviceScan
//
//  Created by YLCHUN on 2017/7/26.
//  Copyright © 2017年 ylchun. All rights reserved.
//
//  获取外网ip通过访问 http://ifconfig.me/ip
//

#import <Foundation/Foundation.h>

typedef NSArray Addrs4;

static Addrs4* Addrs4Marke(NSUInteger A, NSUInteger B, NSUInteger C, NSUInteger D) {
    if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
        return @[@(A), @(B), @(C), @(D)];
    }
    return nil;
}

@interface LANRegion : NSObject
@property (nonatomic, readonly) Addrs4 *radioAddrs;//广播地址
@property (nonatomic, readonly) Addrs4 *netAddrs;//网络地址
@property (nonatomic, readonly) Addrs4 *netMarks;//掩码
@property (nonatomic, readonly) Addrs4 *firstAddrs;//首地址
@property (nonatomic, readonly) Addrs4 *lastAddrs;//尾地址
@property (nonatomic, readonly) NSUInteger netIpCount;//网络主机ip地址数量

-(instancetype)init NS_UNAVAILABLE;

/**
 创建一个网络对象
 
 @param ip 网内ip
 @param mark 网络ip掩码
 @return 成功返回对象，失败返回nil
 */
-(instancetype)initWithIp:(NSString*)ip mark:(NSString*)mark;

/**
 获取字符串地址
 
 @param addrs Addrs4
 @return 成功返回字符串地址，失败返回nil
 */
+(NSString*)stringWithAddrs:(Addrs4*)addrs;

/**
 获取ip对应值
 
 @param addrs Addrs4
 @return ip值
 */
+(NSUInteger)valueWithAddrs:(Addrs4*)addrs;

/**
 获取ip对应值
 
 @param addr Addrs4 String
 @return ip值
 */
+(NSUInteger)valueWithAddr:(NSString*)addr;

@end

@interface LANRegion(Traverse)

/**
 获取网内所有ip列表
 
 @param each 遍历过程中的每一个ip回调
 @return 所有ip地址
 */
-(NSArray<NSString*>*)traverseWithEach:(void(^)(NSString*addr))each;

@end

@interface LANRegion(Current)
@property (nonatomic, readonly) NSString *gatewayIpAddr;//网关ip
@property (nonatomic, readonly) NSString *localIpAddr;//本地ip
@property (nonatomic, readonly) NSString *SSID;//Wi-Fi名称

/**
 获取当前局域网地址信息，移动蜂窝网络下无效
 
 @return 成功返回对象，失败返回nil
 */
+(instancetype)currentRegion;

@end

