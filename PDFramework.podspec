Pod::Spec.new do |spec|
spec.name         = 'PDFramework'
spec.version      = '1.0.3'
spec.license      = { :type => 'MIT' }
spec.homepage     = 'https://github.com/leajiang/PDFramework'
spec.authors      = { "jiangle" => "649498510@qq.com" }
spec.summary      = 'jiangle.'
spec.source       = { :git => 'https://github.com/leajiang/PDFramework.git', :tag =>'1.0.3'  }
spec.platform     = :ios, '8.0'
spec.vendored_frameworks = 'PDFramework.framework'
spec.frameworks   = 'UIKit','AVFoundation','Foundation'
end
