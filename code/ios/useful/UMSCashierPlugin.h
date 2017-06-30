//
//  UMSCashierPlugin.h
//  UMSCashier
//
//  Created by Zoujie on 16/5/19.
//  Copyright © 2016年 UMS. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    CardType_BANK,               //银行卡
    CardType_PREPAY              //预付卡
}CardType;


typedef enum{
    
    CouponType_NO,                 //无优惠
    CouponType_CARD,               //卡打折
    CouponType_TICKET              //券打折
}CouponType;

typedef enum{
	SupportCardType_NoDebitCard,		//不支持借记卡
	SupportCardType_NoCreditCard,	    //不支持贷记卡
	SupportCardType_AllCard,		//支持所有卡
}isSupportLimitCardType;

typedef enum{
    PayStatus_PAYSUCCESS,              //交易成功
    PayStatus_PAYFAIL,                 //交易失败
    PayStatus_PAYTIMEOUT,              //交易超时
    PayStatus_PAYCANCEL,               //交易取消
    
    PayStatus_VOIDSUCCESS,              //撤销成功
    PayStatus_VOIDFAIL,                 //撤销失败
    PayStatus_VOIDTIMEOUT,              //撤销超时
    PayStatus_VOIDCANCEL                //撤销取消
    
}PayStatus;

typedef enum{
    PreAuthType_PREAUTH,               //预授权
    PreAuthType_PREAUTHFIN,            //预授权完成
    PreAuthType_PREAUTHCANCEL,         //预授权撤销
    PreAuthType_PREAUTHFINCANCEL,      //预授权完成撤销
    
}PreAuthType;

typedef enum{
    TransactionStatus_SUCCESS,              //成功
    TransactionStatus_FAIL,                 //失败
    TransactionStatus_TIMEOUT,              //超时
    TransactionStatus_CANCEL,               //取消
    
}TransactionStatus;

typedef enum{
    PayType_EPOS,           //刷卡支付
    PayType_MOBILE          //POS通支付
}PayType;

typedef enum{
    SalesSlipType_AUTO,               //根据设备型号决定签购单类型
    SalesSlipType_PAPER,              //纸质签购单
    SalesSlipType_ELECTRONIC          //电子签购单
}SalesSlipType;

typedef  enum {
    PaperSign_NotUse,
    PaperSign_Use,
}PaperSign;

typedef enum{
    PrintStatus_INITIAL,                  //打印状态的初始值
    PrintStatus_PRINTSUCCESS,             //打印成功
    PrintStatus_PRINTFAIL,                //打印失败
    PrintStatus_NOPAPER,                   //打印机无纸
    PrintStatus_UNPRINT                   //未打印
}PrintStatus;
typedef enum{
    SignatureStatus_INITIAL,             //签名状态的初始值
    SignatureStatus_SUCCESS,             //签名上送成功
    SignatureStatus_FAIL,                //签名上送失败
    SignatureStatus_TIMEOUT,            //超时
    SignatureStatus_UNUPLOAD,           //签名未上送
    SignatureStatus_NRUPLOAD            //签名无需上送
}SignatureStatus;
typedef enum
{
    PaperResult_OK,     //小票打印成功
    PaperResult_NO_PAPER,  //缺纸
    PaperResult_FAIL     //小票打印失败
}PaperResult;

typedef enum {
    InquiryStatus_SUCCESS,  //余额查询成功
    InquiryStatus_FAIL,     //余额查询失败
    InquiryStatus_CANCEL,   //余额查询取消
    InquiryStatus_TIMEOUT   //余额查询超时
}InquiryStatus;

typedef enum {
    RealNameAuthStatus_SUCCESS, //实名认证成功
    RealNameAuthStatus_FAIL,    //实名认证失败
    RealNameAuthStatus_CANCEL,  //实名认证取消
    RealNameAuthStatus_TIMEOUT  //实名认证超时
}RealNameAuthStatus;

typedef enum{
	SelfServiceWithdrawals_SUCCESS,//自助取款成功
	SelfServiceWithdrawals_FAIL,//自助取款失败
	SelfServiceWithdrawals_CANCEL,//自助取款取消
	SelfServiceWithdrawals_TIMEOUT//自助取款超时
}SelfServiceWithdrawalsStatus;

/*
typedef enum{
    SalesSlipFavoriteType_DEFAULT,            //默认情况
    SalesSlipFavoriteType_PAPER,              //纸质签购单
    SalesSlipFavoriteType_ELECTRONIC          //电子签购单
}SalesSlipFavoriteType;
 */


@protocol UMSCashierPluginDelegate <NSObject>

@optional


/*
 // 支付成功返回
 acqNo  收单机构号;
 amount 金额;
 batchNo    出账机构批次号;
 billsMID   出账商户号;
 billsMercName 出账商户名;
 billsTID   出账终端号;
 resultStatus    返回状态;
 resultInfo    错误信息;
 expireDate  信用卡有效期;
 issNo  发卡机构号;
 merchantId 受卡方标识码;
 operator 操作员;
 orderId 订单号;
 pAccount 银行卡号;
 refId 索引参考号;
 termId 受卡方终端标识码;
 dealDate 交易日期;
 dealTime 交易时间;
 txnType 交易类型;
 voucherNo 授权码;
 // 支付失败返回
 resultStatus    返回状态;
 resultInfo    错误信息;
 // 支付超时返回
 resultStatus    错误码;
 resultInfo    错误信息;
 // 支付取消不返回结果
 */
//支付结果回调
-(void)onPayResult:(PayStatus) payStatus PrintStatus:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus withInfo:(NSDictionary *)dict;

/*
 orderId    订单号;
 orderState  订单状态;
 payState   支付状态
 amount   订单金额;
 serverTime    服务器时间
 bankCardId    银行卡号
 bankName      银行卡名称
 boxId         盒子号
 resultStatus    返回状态;
 resultInfo    错误信息;
 memo          备注
 */

//订单查询回调
-(void)onUMSQueryOrder:(NSDictionary *)dict;

/*
 printStatus  补发签购单状态
 resultInfo          错误信息
 */

//补发签购单回调
-(void)onUMSSignOrder:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus ResultInfo:(NSDictionary *)resultInfo;


/*
 resultStatus  返回状态
 resultInfo    错误信息
 deviceId      设备号
 */
//设备激活回调
-(void)onUMSSetupDevice:(BOOL) resultStatus resultInfo:(NSDictionary *)resultInfo withDeviceId:(NSString *)deviceId;

//打印小票回调
-(void)onUMSPrint:(PaperResult) status resultInfo:(NSDictionary *)resultInfo;
/*
 resultStatus  返回状态
 resultInfo    错误信息
 csn           CSN号
 */
//获取CSN回调
-(void)onUMSGetCSN:(BOOL)resultStatus resultInfo:(NSDictionary *)resultInfo;

/**
 *  预授权回调(包括预授权, 预授权完成, 预授权撤销, 预授权完成撤销)
 *
 *  @param preAuthType       预授权业务类型
 *  @param transactionStatus 返回业务状态
 *  @param printStatus       打印状态
 *  @param printStatus       签购单打印状态
 *  @param dict              预授权返回信息
 */
-(void)onUMSPreAuth:(PreAuthType)preAuthType TransactionStatus:(TransactionStatus)transactionStatus PrintStatus:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus withInfo:(NSDictionary *)dict;

/**
 *  获取SDK信息回调
 *
 *  @param dic 回调信息 environment:0测试1生产  versionName:版本号
 */
-(void)onUMSCheckCurrentEnv:(NSDictionary *)dic;


/**
 * 获取卡号回调
 */
-(void)onUMSReturnCardNum:(NSDictionary *)dic;

/**
 *  联机退货回调
 *  @param transactionStatus 返回业务状态
 *  @param printStatus       打印状态
 *  @param printStatus       签购单打印状态
 *  @param dict              联机退货返回信息
 */
-(void)onUMSRefund:(TransactionStatus)transactionStatus PrintStatus:(PrintStatus) printStatus SignatureStatus:(SignatureStatus)uploadStatus withInfo:(NSDictionary *)dict;

/**
 *  余额查询回调
 *
 *  @param inquiryStatus 返回业务状态
 *  @param dict          余额查询返回信息
 */
-(void)onUMSBalanceInquiry:(InquiryStatus)inquiryStatus withInfo:(NSDictionary *)dict;

/**
 *  查询当日交易并打印回调
 *
 *  @param PrintStatus 返回业务状态
 *  @param status        打印状态
 *  @param resultInfo    当日交易查询返回信息
 */
-(void)onUMSQueryTodayTradeAndPrint:(PrintStatus) status resultInfo:(NSDictionary *)resultInfo;


/*
 *  检查网络状态回调
 *  @param dic              网络状态返回信息
 *
 */
//-(void)oncheckNetworkInfo:(NSDictionary *)dict;

/*
 *  自助取款回调
 * SelfServiceWithdrawalsStatus     调用接口状态;
 * amount   订单金额;
 * billsMID   出账商户号;
 * billsTID   出账终端号;
 * dealTime 交易时间;
 * operator 操作员;
 * resultStatus    返回状态;
 * resultInfo    错误信息;
 *
 */
-(void)onUMSSelfServiceWithdrawals:(SelfServiceWithdrawalsStatus)resultStatus resultInfo:(NSDictionary *)resultInfo;
@end

/*=================================================================================================================================*/

@interface UMSCashierPlugin : NSObject

/*
 设备激活
 
 params  参数字典{
 billsMID    商户号 必传
 billsTID    终端号 必传
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 
 */
+(void)umsSetupDevice:(NSDictionary *)params
       ViewController:(UIViewController *)controller
             Delegate:(id<UMSCashierPluginDelegate>)delegate;


/*
 (支付)消费
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 amount             金额(分)   必传
 merOrderId         商户订单号   必传
 merOrderDesc       商户订单描述
 operatorID         操作员号    必传
 payType            支付方式    传@"epos"或其他值或不传,使用epos支付,传@"mobile"使用pos通支付
 serialNum          支付串码    当payType传mobile时，传入serialNum可直接支付，无需扫码或者输入串码
 memo               备注
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 isShowOrderInfo    是否显示订单详情页面,页面内容从memo中获取.memo按特定格式. 传@"NO"或其他值或不传,不显示详情页面,传@"YES"显示详情页面
 cardType           使用卡类型   传@"bank"或其他值或不传,使用银行卡 传@"prepay"使用预付卡
 couponType         优惠类型    传@"NO"或其他值或不传,不使用优惠,传@"card"使用银行卡优惠,传@"ticket"使用优惠券
 couponNo           优惠券代码   在couponType传@"ticket"时必传,其他情况不验证
 consumerPhone      消费者手机号
 orgCode            组织机构代码  cardType传@"prepay"预付卡使用,某些预付卡需要该字段
 unsupportedCardType  卡种限制  传@"NO"或其他值或不传,默认全部支持,传@"nodebitcard"不支持借记卡，传@“nocreditcard”不支持贷记卡
 isUsePaperSign     是否使用小票签名(而不是电子签名) 传@"NO"或其他值或不传使用默认电子签名,传@"YES"跳过电子签名(需要消费者在小票上签名)
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 extension          备注字段
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPay:(NSDictionary *)params
ViewController:(UIViewController *)controller
     Delegate:(id<UMSCashierPluginDelegate>)delegate;


/*
 订单查询
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 orderId            银商订单号   与merOrderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 merOrderId         商户订单号   与orderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 ums_request 接口所有传入参数JSON字符串
 }
 delegate       回调
 */
+(void)umsQueryOrder:(NSDictionary *)params
            Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 支付撤销(消费撤销)
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 orderId            银商订单号   与merOrderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 merOrderId         商户订单号   与orderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 operatorID         操作员号    必传
 payType            支付方式    传@"epos"或其他值或不传,epos消费撤销,传@"mobile"pos通消费撤销
 memo               备注
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 cardType           使用卡类型   传@"bank"或其他值或不传,使用银行卡 传@"prepay"使用预付卡
 orgCode            组织机构代码  cardType传@"prepay"预付卡使用,某些预付卡需要该字段
 consumerPhone      消费者手机号
 isUsePaperSign     是否使用小票签名(而不是电子签名) 传@"NO"或其他值或不传使用默认电子签名,传@"YES"跳过电子签名(需要消费者在小票上签名)
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsCancelOrder:(NSDictionary *)params
       ViewController:(UIViewController *)controller
             Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 重发签购单
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 orderId            银商订单号   与merOrderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 merOrderId         商户订单号   与orderId两者至少传一个,两者均传则以orderId为准.强烈建议传orderId
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsSignOrder:(NSDictionary *)params
     ViewController:(UIViewController *)controller
           Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 商户小票打印
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 message            需打印内容   必传
 ums_request        接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPrint:(NSDictionary *)params
 ViewController:(UIViewController *)controller
       Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 获取CSN
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsGetCSN:(NSDictionary *)params
  ViewController:(UIViewController *)controller
        Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 预授权
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 amount             金额(分)   必传
 merOrderId         商户订单号   必传
 merOrderDesc       商户订单描述
 operatorID         操作员号    必传
 memo               备注
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 consumerPhone      消费者手机号
 isSupportDebitCard     是否支持借记卡 传@"YES"或其他值或不传,支持借记卡和信用卡,传@"NO"仅支持信用卡
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPreAuth:(NSDictionary *)params
   ViewController:(UIViewController *)controller
         Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 预授权完成
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 finAmount          预授权完成金额(分)   必传
 merOrderId         商户订单号   必传
 merOrderDesc       商户订单描述
 originOrderId      原预授权银商订单号   必传
 originAuthNo       原预授权返回的授权码  必传
 operatorID         操作员号    必传
 memo               备注
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 consumerPhone      消费者手机号
 isNeedSign         是否需要电子签名 传@"YES"或其他值或不传,支持需要签名,传@"NO"不需要签名
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 useBankcard        是否需要银行卡  传@"YES"为银行卡流程，传"NO"或其他值或不传，不需要银行卡
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPreAuthFin:(NSDictionary *)params
      ViewController:(UIViewController *)controller
            Delegate:(id<UMSCashierPluginDelegate>)delegate;
/*
 预授权撤销
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 originOrderId      原预授权银商订单号   必传
 originAuthNo       原预授权返回的授权码  必传
 originMerOrderId   原预授权商户订单号
 operatorID         操作员号    必传
 memo               备注
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 useBankcard        是否需要银行卡  传@"YES"为银行卡流程，传"NO"或其他值或不传，不需要银行卡
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPreAuthCancel:(NSDictionary *)params
         ViewController:(UIViewController *)controller
               Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 预授权完成撤销
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 originOrderId      原预授权银商订单号   必传
 originAuthNo       原预授权返回的授权码  必传
 originMerOrderId   原预授权商户订单号
 operatorID         操作员号    必传
 memo               备注
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 useBankcard        是否需要银行卡  传@"YES"为银行卡流程，传"NO"或其他值或不传，不需要银行卡
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsPreAuthFinCancel:(NSDictionary *)params
            ViewController:(UIViewController *)controller
                  Delegate:(id<UMSCashierPluginDelegate>)delegate;

/**
 *  获取SDK信息
 *
 *  @param delegate 回调
 */

+(void)umsCheckCurrentEnv:(NSDictionary *)params
                 Delegate:(id<UMSCashierPluginDelegate>)delegate;

/**
 *  获取银行卡号
 *	ums_request 接口所有传入参数JSON字符串
 *  @param controller       调用接口的UIViewController
 *  @param delegate         回调
 */

+(void)umsGetCardNum:(NSDictionary *)params
      ViewController:(UIViewController *)controller
            Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 联机退货
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 amount             退货金额，单位为分 必传
 merOrderId         商户订单号   必传
 merOrderDesc       商户订单描述
 originOrderId      原消费的银商订单号   必传
 operatorID         操作员号    必传
 memo               备注
 consumerPhone      消费者手机号
 salesSlipType      签购单类型   现在默认值为@"auto",根据pos机器类型自动选择签购单类型
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsRefund:(NSDictionary *)params
  ViewController:(UIViewController *)controller
        Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 余额查询
 
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsBalanceInquiry:(NSDictionary *)params
          ViewController:(UIViewController *)controller
                Delegate:(id<UMSCashierPluginDelegate>)delegate;

/*
 查询当日交易并打印
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */

+(void)umsQueryTodayTradeAndPrint:(NSDictionary *)params
                   ViewController:(UIViewController *)controller
                         Delegate:(id<UMSCashierPluginDelegate>)delegate;
/*
 自助取款
 params  参数字典{
 billsMID           商户号 必传
 billsTID           终端号 必传
 amount             取款金额，单位为分 必须传入100整数倍 必传
 merOrderId         商户订单号   必传
 merOrderDesc       商户订单描述
 operatorID         操作员号
 sign               商户端对入参的签名字符串 商户自行对数据加签获取sign，传入此接口
 ums_request 接口所有传入参数JSON字符串
 }
 controller     调用接口的UIViewController
 delegate       回调
 */
+(void)umsSelfServiceWithdrawals:(NSDictionary *)params
				  ViewController:(UIViewController *)controller
						Delegate:(id<UMSCashierPluginDelegate>) delegate;
@end
