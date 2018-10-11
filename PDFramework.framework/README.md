# MWPhotoBrowser

<!--[![CI Status](http://img.shields.io/travis/Michael Waterfall/MWPhotoBrowser.svg?style=flat)](https://travis-ci.org/Michael Waterfall/MWPhotoBrowser)-->
[![Version](https://img.shields.io/cocoapods/v/MWPhotoBrowser.svg?style=flat)](http://cocoapods.org/pods/MWPhotoBrowser)
[![License](https://img.shields.io/cocoapods/l/MWPhotoBrowser.svg?style=flat)](http://cocoapods.org/pods/MWPhotoBrowser)
[![Platform](https://img.shields.io/cocoapods/p/MWPhotoBrowser.svg?style=flat)](http://cocoapods.org/pods/MWPhotoBrowser)

[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=mwaterfall&url=https://github.com/mwaterfall/MWPhotoBrowser&title=MWPhotoBrowser&language=&tags=github&category=software)

## A simple iOS photo and video browser with optional grid view, captions and selections.

MWPhotoBrowser can display one or more images or videos by providing either `UIImage` objects, `PHAsset` objects, or URLs to library assets, web images/videos or local files. The photo browser handles the downloading and caching of photos from the web seamlessly. Photos can be zoomed and panned, and optional (customisable) captions can be displayed.

The browser can also be used to allow the user to select one or more photos using either the grid or main image view.

[![Alt][screenshot1_thumb]][screenshot1]    [![Alt][screenshot2_thumb]][screenshot2]    [![Alt][screenshot3_thumb]][screenshot3]    [![Alt][screenshot4_thumb]][screenshot4]    [![Alt][screenshot5_thumb]][screenshot5]    [![Alt][screenshot6_thumb]][screenshot6]

[screenshot1_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser1t.png
[screenshot1]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser1.png
[screenshot2_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser2t.png
[screenshot2]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser2.png
[screenshot3_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser3t.png
[screenshot3]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser3.png
[screenshot4_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser4t.png
[screenshot4]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser4.png
[screenshot5_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser5t.png
[screenshot5]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser5.png
[screenshot6_thumb]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser6t.png
[screenshot6]: https://raw.github.com/mwaterfall/MWPhotoBrowser/master/Screenshots/MWPhotoBrowser6.png

Works on iOS 7+. All strings are localisable so they can be used in apps that support multiple languages.

## Usage

MWPhotoBrowser is designed to be presented within a navigation controller. Simply set the delegate (which must conform to `MWPhotoBrowserDelegate`) and implement the 2 required delegate methods to provide the photo browser with the data in the form of `MWPhoto` objects. You can create an `MWPhoto` object by providing a `UIImage` object, `PHAsset` object, or a URL containing the path to a file, an image online or an asset from the asset library.

`MWPhoto` objects handle caching, file management, downloading of web images, and various optimisations for you. If however you would like to use your own data model to represent photos you can simply ensure your model conforms to the `MWPhoto` protocol. You can then handle the management of caching, downloads, etc, yourself. More information on this can be found in `MWPhotoProtocol.h`.

See the code snippet below for an example of how to implement the photo browser. There is also a simple demo app within the project.

```obj-c
// Create array of MWPhoto objects
self.photos = [NSMutableArray array];

// Add photos
[photos addObject:[MWPhoto photoWithURL:[NSURL fileURLWithPath:[[NSBundle mainBundle] pathForResource:@"photo2l" ofType:@"jpg"]]]];
[photos addObject:[MWPhoto photoWithURL:[NSURL URLWithString:@"http://farm4.static.flickr.com/3629/3339128908_7aecabc34b.jpg"]]];
[photos addObject:[MWPhoto photoWithURL:[NSURL URLWithString:@"http://farm4.static.flickr.com/3590/3329114220_5fbc5bc92b.jpg"]]];

// Add video with poster photo
MWPhoto *video = [MWPhoto photoWithURL:[NSURL URLWithString:@"https://scontent.cdninstagram.com/hphotos-xpt1/t51.2885-15/e15/11192696_824079697688618_1761661_n.jpg"]];
video.videoURL = [[NSURL alloc] initWithString:@"https://scontent.cdninstagram.com/hphotos-xpa1/t50.2886-16/11200303_1440130956287424_1714699187_n.mp4"];
[photos addObject:video];

// Create browser (must be done each time photo browser is
// displayed. Photo browser objects cannot be re-used)
MWPhotoBrowser *browser = [[MWPhotoBrowser alloc] initWithDelegate:self];

// Set options
browser.displayActionButton = YES; // Show action button to allow sharing, copying, etc (defaults to YES)
browser.displayNavArrows = NO; // Whether to display left and right nav arrows on toolbar (defaults to NO)
browser.displaySelectionButtons = NO; // Whether selection buttons are shown on each image (defaults to NO)
browser.zoomPhotosToFill = YES; // Images that almost fill the screen will be initially zoomed to fill (defaults to YES)
browser.alwaysShowControls = NO; // Allows to control whether the bars and controls are always visible or whether they fade away to show the photo full (defaults to NO)
browser.enableGrid = YES; // Whether to allow the viewing of all the photo thumbnails on a grid (defaults to YES)
browser.startOnGrid = NO; // Whether to start on the grid of thumbnails instead of the first photo (defaults to NO)
browser.autoPlayOnAppear = NO; // Auto-play first video

// Customise selection images to change colours if required
browser.customImageSelectedIconName = @"ImageSelected.png";
browser.customImageSelectedSmallIconName = @"ImageSelectedSmall.png";

// Optionally set the current visible photo before displaying
[browser setCurrentPhotoIndex:1];

// Present
[self.navigationController pushViewController:browser animated:YES];

// Manipulate
[browser showNextPhotoAnimated:YES];
[browser showPreviousPhotoAnimated:YES];
[browser setCurrentPhotoIndex:10];
```

Then respond to the required delegate methods:

```obj-c
- (NSUInteger)numberOfPhotosInPhotoBrowser:(MWPhotoBrowser *)photoBrowser {
    return self.photos.count;
}

- (id <MWPhoto>)photoBrowser:(MWPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index {
    if (index < self.photos.count) {
        return [self.photos objectAtIndex:index];
    }
    return nil;
}
```

You can present the browser modally simply by wrapping it in a new navigation controller and presenting that. The demo app allows you to toggle between the two presentation types.


### Videos

You can represent videos in MWPhoto objects by providing a standard MWPhoto image object with a `videoURL`. You can also use a `PHAsset` object or a URL to an assets library video.

```obj-c

// Video with URL including poster photo
MWPhoto *video = [MWPhoto photoWithURL:[NSURL URLWithString:@"https://scontent.cdninstagram.com/hphotos-xpt1/t51.2885-15/e15/11192696_824079697688618_1761661_n.jpg"]];
video.videoURL = [NSURL URLWithString:@"https://scontent.cdninstagram.com/hphotos-xpa1/t50.2886-16/11200303_1440130956287424_1714699187_n.mp4"];

// Video with PHAsset
MWPhoto *video = [MWPhoto photoWithAsset:asset targetSize:[UIScreen mainScreen].bounds.size]; // Example sizing

// Video with ALAsset
MWPhoto *video = [MWPhoto photoWithURL:asset.defaultRepresentation.url];
if ([asset valueForProperty:ALAssetPropertyType] == ALAssetTypeVideo) {
    photo.videoURL = asset.defaultRepresentation.url;
}

// Video with no poster photo
MWPhoto *video = [MWPhoto videoWithURL:[NSURL URLWithString:@"https://scontent.cdninstagram.com/hphotos-xfa1/t50.2886-16/11237510_945154435524423_2137519922_n.mp4"]];

// Video grid thumbnail
MWPhoto *videoThumb = [MWPhoto photoWithURL:[NSURL URLWithString:@"https://scontent.cdninstagram.com/hphotos-xaf1/t51.2885-15/s150x150/e15/11240463_963135443745570_1519872157_n.jpg"]];
videoThumb.isVideo = YES;

// Video grid thumbnail for video with no poster photo
MWPhoto *videoThumb = [MWPhoto new];
videoThumb.isVideo = YES;

```


### Grid

In order to properly show the grid of thumbnails, you must ensure the property `enableGrid` is set to `YES`, and implement the following delegate method:

```obj-c
- (id <MWPhoto>)photoBrowser:(MWPhotoBrowser *)photoBrowser thumbPhotoAtIndex:(NSUInteger)index;
```

The photo browser can also start on the grid by enabling the `startOnGrid` property.


### Actions

By default, if the action button is visible then the image (and caption if it exists) are sent to a UIActivityViewController.

You can provide a custom action by implementing the following delegate method:

```obj-c
- (void)photoBrowser:(MWPhotoBrowser *)photoBrowser actionButtonPressedForPhotoAtIndex:(NSUInteger)index {
    // Do your thing!
}
```


### Photo Captions

Photo captions can be displayed simply by setting the `caption` property on specific photos:

```obj-c
MWPhoto *photo = [MWPhoto photoWithURL:[NSURL URLWithString:@"http://farm4.static.flickr.com/3629/3339128908_7aecabc34b.jpg"]];
photo.caption = @"Campervan";
```

No caption will be displayed if the caption property is not set.


#### Custom Captions

By default, the caption is a simple black transparent view with a label displaying the photo's caption in white. If you want to implement your own caption view, follow these steps:

1. Optionally use a subclass of `MWPhoto` for your photos so you can store more data than a simple caption string.
2. Subclass `MWCaptionView` and override `-setupCaption` and `-sizeThatFits:` (and any other UIView methods you see fit) to layout your own view and set it's size. More information on this can be found in `MWCaptionView.h`
3. Implement the `-photoBrowser:captionViewForPhotoAtIndex:` MWPhotoBrowser delegate method (shown below).

Example delegate method for custom caption view:

```obj-c
- (MWCaptionView *)photoBrowser:(MWPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index {
    MWPhoto *photo = [self.photos objectAtIndex:index];
    MyMWCaptionViewSubclass *captionView = [[MyMWCaptionViewSubclass alloc] initWithPhoto:photo];
    return captionView;
}
```


#### Selections

The photo browser can display check boxes allowing the user to select one or more of the photos. To use this feature, simply enable the `displaySelectionButtons` property, and implement the following delegate methods:

```obj-c
- (BOOL)photoBrowser:(MWPhotoBrowser *)photoBrowser isPhotoSelectedAtIndex:(NSUInteger)index {
    return [[_selections objectAtIndex:index] boolValue];
}

- (void)photoBrowser:(MWPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index selectedChanged:(BOOL)selected {
    [_selections replaceObjectAtIndex:index withObject:[NSNumber numberWithBool:selected]];
}
```


## Installation

MWPhotoBrowser is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "MWPhotoBrowser"
```


## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

Then import the photo browser into your source files (or into your bridging header if you're using with Swift and not using frameworks with Cocoapods):

```obj-c
#import "MWPhotoBrowser.h"
```

If you are using Swift and frameworks, then you can just import the browser into your Swift source file:

```swift
import MWPhotoBrowser
```


## Author

Michael Waterfall, michael@d3i.com


## License

MWPhotoBrowser is available under the MIT license. See the LICENSE file for more info.


## Notes

Demo photos kindly provided by [Oliver Waters](<http://twitter.com/oliverwaters>).
// Hide the title of refresh status
footer.refreshingTitleHidden = YES;
// If does have not above method，then use footer.stateLabel.hidden = YES;
```
![(上拉刷新03-隐藏刷新状态的文字)](http://images0.cnblogs.com/blog2015/497279/201506/141205200985774.gif)

## <a id="The_pull_to_refresh_04-All_loaded"></a>The pull to refresh 04-All loaded
```objc
//Become the status of NoMoreData
[footer noticeNoMoreData];
```
![(上拉刷新04-全部加载完毕)](http://images0.cnblogs.com/blog2015/497279/201506/141205248634686.gif)

## <a id="The_pull_to_refresh_05-DIY_title"></a>The pull to refresh 05-DIY title
```objc
// Set title
[footer setTitle:@"Click or drag up to refresh" forState:MJRefreshStateIdle];
[footer setTitle:@"Loading more ..." forState:MJRefreshStateRefreshing];
[footer setTitle:@"No more data" forState:MJRefreshStateNoMoreData];

// Set font
footer.stateLabel.font = [UIFont systemFontOfSize:17];

// Set textColor
footer.stateLabel.textColor = [UIColor blueColor];
```
![(上拉刷新05-自定义文字)](http://images0.cnblogs.com/blog2015/497279/201506/141205295511153.gif)

## <a id="The_pull_to_refresh_06-Hidden_After_loaded"></a>The pull to refresh 06-Hidden After loaded
```objc
//Hidden current control of the pull to refresh
self.tableView.mj_footer.hidden = YES;
```
![(上拉刷新06-加载后隐藏)](http://images0.cnblogs.com/blog2015/497279/201506/141205343481821.gif)

## <a id="The_pull_to_refresh_07-Automatic_back_of_the_pull01"></a>The pull to refresh 07-Automatic back of the pull01
```objc
self.tableView.mj_footer = [MJRefreshBackNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMoreData)];
```
![(上拉刷新07-自动回弹的上拉01)](http://images0.cnblogs.com/blog2015/497279/201506/141205392239231.gif)

## <a id="The_pull_to_refresh_08-Automatic_back_of_the_pull02"></a>The pull to refresh 08-Automatic back of the pull02
```objc
MJRefreshBackGifFooter *footer = [MJRefreshBackGifFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMoreData)];

// Set the normal state of the animated image
[footer setImages:idleImages forState:MJRefreshStateIdle];
//  Set the pulling state of animated images（Enter the status of refreshing as soon as loosen）
[footer setImages:pullingImages forState:MJRefreshStatePulling];
// Set the refreshing state of animated images
[footer setImages:refreshingImages forState:MJRefreshStateRefreshing];

// Set footer
self.tableView.mj_footer = footer;
```
![(上拉刷新07-自动回弹的上拉02)](http://images0.cnblogs.com/blog2015/497279/201506/141205441443628.gif)

## <a id="The_pull_to_refresh_09-DIY_the_control_of_refresh(Automatic_refresh)"></a>The pull to refresh 09-DIY the control of refresh(Automatic refresh)
```objc
self.tableView.mj_footer = [MJDIYAutoFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMoreData)];
// Implementation reference to MJDIYAutoFooter.h和MJDIYAutoFooter.m
```
![(上拉刷新09-自定义刷新控件(自动刷新))](http://images0.cnblogs.com/blog2015/497279/201506/141205500195866.gif)

## <a id="The_pull_to_refresh_10-DIY_the_control_of_refresh(Automatic_back)"></a>The pull to refresh 10-DIY the control of refresh(Automatic back)
```objc
self.tableView.mj_footer = [MJDIYBackFooter footerWithRefreshingTarget:self refreshingAction:@selector(loadMoreData)];
// Implementation reference to MJDIYBackFooter.h和MJDIYBackFooter.m
```
![(上拉刷新10-自定义刷新控件(自动回弹))](http://images0.cnblogs.com/blog2015/497279/201506/141205560666819.gif)

## <a id="UICollectionView01-The_pull_and_drop-down_refresh"></a>UICollectionView01-The pull and drop-down refresh
```objc
// The drop-down refresh
self.collectionView.mj_header = [MJRefreshNormalHeader headerWithRefreshingBlock:^{
   //Call this Block When enter the refresh status automatically 
}];

// The pull to refresh
self.collectionView.mj_footer = [MJRefreshAutoNormalFooter footerWithRefreshingBlock:^{
   //Call this Block When enter the refresh status automatically
}];
```
![(UICollectionView01-上下拉刷新)](http://images0.cnblogs.com/blog2015/497279/201506/141206021603758.gif)

## <a id="UIWebView01-The_drop-down_refresh"></a>UIWebView01-The drop-down refresh
```objc
//Add the control of The drop-down refresh
self.webView.scrollView.mj_header = [MJRefreshNormalHeader headerWithRefreshingBlock:^{
   //Call this Block When enter the refresh status automatically
}];
```
![(UICollectionView01-上下拉刷新)](http://images0.cnblogs.com/blog2015/497279/201506/141206080514524.gif)

## Remind
* ARC
* iOS>=6.0
* iPhone \ iPad screen anyway

## <a id="Hope"></a>Hope
* If you find bug when used，Hope you can Issues me，Thank you or try to download the latest code of this framework to see the BUG has been fixed or not）
* If you find the function is not enough when used，Hope you can Issues me，I very much to add more useful function to this framework ，Thank you !
* If you want to contribute code for MJRefresh，please Pull Requests me
*  If you use MJRefresh in your develop app，Hope you can go to[CocoaControls](https://www.cocoacontrols.com/controls/mjrefresh)to add the iTunes path
 of you app，I Will install your app，and according to the usage of many app，to be a better design and improve to MJRefresh，Thank you !
   * StepO1（WeChat is just an Example，Explore“Your app name itunes”）
![(step01)](http://ww4.sinaimg.cn/mw1024/800cdf9ctw1eq0viiv5rsj20sm0ea41t.jpg)
   * StepO2
![(step02)](http://ww2.sinaimg.cn/mw1024/800cdf9ctw1eq0vilejxlj20tu0me7a0.jpg)
   * StepO3
![(step03)](http://ww1.sinaimg.cn/mw1024/800cdf9ctw1eq0viocpo5j20wc0dc0un.jpg)
   * StepO4
![(step04)](http://ww3.sinaimg.cn/mw1024/800cdf9ctw1eq0vir137xj20si0gewgu.jpg)
