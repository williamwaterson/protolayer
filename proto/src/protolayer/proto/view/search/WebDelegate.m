#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>
#import "WebDelegate.h"

void openUrl(HIViewRef webView, CFStringRef inUrl)
{
  CFURLRef url = CFURLCreateWithString(NULL, inUrl, NULL);
  
  WebView* nativeView;
  nativeView = (WebView*) HIWebViewGetWebView(webView);
  NSURLRequest* request = [NSURLRequest requestWithURL:(NSURL*) url];

  WebFrame* mainFrame;
  mainFrame = [nativeView mainFrame];
  [mainFrame loadRequest:request];
}
