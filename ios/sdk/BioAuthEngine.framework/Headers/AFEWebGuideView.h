//
//  AFEWebGuideView.h
//  BioAuthEngine
//
//  Created by yukun.tyk on 3/21/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BioAuthEngine/AFEStatusBar.h>
#import <WebKit/WebKit.h>
@protocol AFEWebGuideViewDelegate <NSObject>

- (void)onButtonBegin;
- (void)onButtonCancel;

@optional
- (void)onLoadFinished:(BOOL)success;
- (void)onH5Logger:(NSString *)h5Logger;
- (void)onButtonAgreement;

@end



@interface AFEWebGuideView : UIView <IStatusBarDelegate,WKScriptMessageHandler, WKUIDelegate, WKNavigationDelegate>

//@property (strong, nonatomic)  UIWebView *webView;
@property(strong,nonatomic) WKWebView *wkwebView;

@property(nonatomic, assign)BOOL loaded;

- (void)setWebGuideViewDelegate:(id<AFEWebGuideViewDelegate>)webGuideViewDeleage;
- (void)setURL:(NSURL *)url;

/**
 *  废弃接口，脱敏姓名改由服务端下发
 */
- (void)setUserName:(NSString *)uName;

@end
