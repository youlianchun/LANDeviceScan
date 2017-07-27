# LANDeviceScan
局域网设备扫描

#import <LANRegionARP/LANRegionARP.h>

[[LANRegionARP share] arpInfos:^(LANRegion *lanRegion, NSArray<ARPInfo *> *infos) {

    //code...
    
}];
