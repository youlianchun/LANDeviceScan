//
//  TableViewController.m
//  LANDeviceScan
//
//  Created by YLCHUN on 2017/7/26.
//  Copyright © 2017年 ylchun. All rights reserved.
//

#import "TableViewController.h"
#import <LANRegionARP/LANRegionARP.h>

@interface TableViewController ()
@property (nonatomic, copy) NSArray *array;
@end

@implementation TableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)scanAction:(UIBarButtonItem *)sender {
    sender.enabled = NO;
    [[LANRegionARP share] arpInfos:^(LANRegion *lanRegion, NSArray<ARPInfo *> *infos) {
        sender.enabled = YES;
        self.array = infos;
        [self.tableView reloadData];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.array.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    ARPInfo *info = self.array[indexPath.row];
    cell.textLabel.text = info.ipAddr;
    cell.detailTextLabel.text = info.macAddr;
    cell.accessoryType = UITableViewCellAccessoryNone;
    if (info.isLocal) {
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    }
    if (info.isGateway) {
        cell.accessoryType = UITableViewCellAccessoryDetailButton;
    }
    return cell;
}

@end
