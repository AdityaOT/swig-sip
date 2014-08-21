//
//  SWEndpoint.h
//  swig
//
//  Created by Pierre-Marc Airoldi on 2014-08-20.
//  Copyright (c) 2014 PeteAppDesigns. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SWAccount.h"

@class SWEndpointConfiguration, SWAccount, SWCall;

@interface SWEndpoint : NSObject

/**
 * gets singleton object.
 * @return singleton
 */
+(SWEndpoint*)sharedInstance;
-(void)configure:(SWEndpointConfiguration *)configuration completionHandler:(void(^)(NSError *error))handler; //configure and start endpoint
//-(void)start:(void(^)(NSError *error))handler;
-(void)reset:(void(^)(NSError *error))handler; //reset endpoint
-(void)addAccount:(SWAccount *)account;
-(SWAccount *)lookupAccount:(NSInteger)accountId;

-(void)setAccountIncomingCallBlock:(void(^)(SWAccount *account, SWCall *call))accountIncomingCallBlock;
-(void)setAccountStateChangeBlock:(void(^)(SWAccount *account, SWAccountState state))accountStateChangeBlock;

@end