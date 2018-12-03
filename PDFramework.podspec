Pod::Spec.new do |spec|
spec.name         = 'PDFramework'
spec.version      = '1.1.4'
spec.license      = { :type => 'MIT' }
spec.homepage     = 'https://github.com/leajiang/PDFramework'
spec.authors      = { "jiangle" => "649498510@qq.com" }
spec.summary      = 'jiangle.'
spec.source       = { :git => 'https://github.com/leajiang/PDFramework.git', :tag =>'1.1.4'  }
spec.platform     = :ios, '8.0'
spec.vendored_frameworks = 'PDFramework.framework'
spec.frameworks   = 'UIKit','AVFoundation','Foundation'
spec.dependency 'AFNetworking'
spec.dependency 'MJRefresh'
spec.dependency 'MWPhotoBrowser'
spec.dependency 'SDWebImage'
spec.dependency 'MBProgressHUD'
spec.dependency 'DACircularProgress'
spec.dependency 'Masonry'
spec.dependency 'IQKeyboardManager'
spec.dependency 'Hyphenate','~>3.5.1'
end
