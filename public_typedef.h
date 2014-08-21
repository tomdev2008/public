/*
 * public_typedef.h
 *
 *  Created on: 2011-12-1
 *      Author: jimm
 */

#ifndef PUBLIC_TYPEDEF_H_
#define PUBLIC_TYPEDEF_H_

#include "common/common_typedef.h"
#include "../lightframe/frame_msg_impl.h"  //IMsgBody的定义

typedef uint8_t						RegionType;
enum
{
	enmInvalidRegionType	= 0x00,
};

typedef uint16_t					RegionID;
enum
{
	enmInvalidRegionID		= 0x0000,      //无效的分区号
	enmRegionID_179ktv      = 0x0001,      //179ktv分区
	enmRegionID_ChatBar     = 0x0002,      //聊吧
	enmRegionID_Show        = 0x0003,      //秀场
};

typedef uint8_t						ChannelType;
enum
{
	enmInvalidChannelType	= 0x00,
};

typedef uint32_t					ChannelID;
enum
{
	enmInvalidChannelID		= 0x0000,
};

/*
*  房间类型
*/
typedef uint8_t						RoomType;
enum
{
	enmInvalidRoomType		= 0x00,   /*无效的*/
	enmRoomType_Sing        = 0x01,   /*唱歌房间*/
	enmRoomType_Dance       = 0x02,   /*跳舞房间*/
	enmRoomType_Chat        = 0x03,   /*聊吧房间*/
	enmRoomType_NewPlayer   = 0x04,   /*新手房间*/
};

/*
* 房间获得类型
*/
typedef uint8_t                    RoomGetType;
enum
{
	enmRoomGetType_None          = 0x00,   /*无效的房间获得类型*/
	enmRoomGetType_Apply         = 0x01,   /*申请获得*/
	enmRoomGetType_Buy           = 0x02,   /*购买获得*/
};

/*
* 消息类型：请求， 响应，通知
*/
typedef uint8_t  MsgType;
enum
{
	enmMsgType_Invalid   = 0x00,
	enmMsgType_Request   = 0x01, 
	enmMsgType_Response  = 0x02, 
	enmMsgType_Notice    = 0x03, 
};

typedef uint32_t					RoomID;
enum
{
	enmInvalidRoomID		= 0x0000,
};

typedef uint8_t						PunishType;
enum
{
	enmInvalidPunishType	= 0x00,
};

typedef uint8_t						PunishReason;
enum
{
	enmInvalidPunishReason	= 0x00,
};

typedef int32_t						RoomIndex;
enum
{
	enmInvalidRoomIndex		= -1,
};
typedef int32_t						ChannelIndex;
enum
{
	enmInvalidChannelIndex	= -1,
};

typedef int32_t						MediaIndex;
enum
{
	enmInvalidMediaIndex	= -1,
};

typedef uint8_t						AccountType;
enum
{
	enmAccountType_Visitor	= 	0x00,   //游客
	enmAccountType_179		=	0x01,   //179注册用户
//	enmAccountType_51		=	0x02,   //51用户
	enmAccountType_QQ       =   0x02,   //腾讯用户
	enmInvalidAccountType   =   0xff,   //无效账户类型
};

typedef uint32_t					AccountID;
enum
{
	enmInvalidAccountID		= 0x00
};

typedef uint16_t					ItemID;
enum
{
	enmInvalidItemID		= 0x0000,
};

typedef uint8_t						UseMeans;
enum
{
	enmInvalidUseMeans		= 0x00,
	enmUseMeans_Count		= 0x01,		//计数
	enmUseMeans_Time		= 0x02,		//计时
};

struct GoodInfo
{
	ItemID			nItemID;
	int32_t			nCount;				//数量
	int32_t			nOwnTick;			//拥有时刻
	int32_t			nKeepTime;			//保存时间
};

struct ItemUnit
{
	ItemID			nItemID;
	UseMeans		nUseMeans;			//使用方式
	int32_t			nQuantity;			//数量（其含义取决于使用方式）
	int32_t			nOwnTick;			//物品拥有时刻
};

typedef uint8_t						ItemTarget;
enum
{
	enmInvalidItemTarget				= 0x00,
	enmItemTarget_EveryoneExceptSelf	= 0x01,		//除自己外的其他任何人
	enmItemTarget_Everyone				= 0x02,		//任何人，包括自己
	enmItemTarget_Self					= 0x03,		//仅仅对自己可用
	enmItemTarget_Nobody				= 0x04,		//不对人使用
};

typedef uint8_t						ItemRange;
enum
{
	enmInvalidItemRange					= 0x00,
	enmItemRange_One					= 0x01,		//只对一个人
	enmItemRange_AllInRoom				= 0x02,		//对房间所有有效用户
	enmItemRange_ManagementInRoom		= 0x03,		//对房间管理层(正式管理员，副室主，室主)
	enmItemRange_NormalInRoom			= 0x04,		//对房间所有普通用户
	enmItemRange_AllInRegion			= 0x05,		//所有分区内的玩家
	enmItemRange_All					= 0x06,		//所有玩家
};

typedef uint8_t						CompareOperator;
enum
{
	enmInvalidCompareOperator			= 0x00,
	enmCompareOperator_Eq				= 0x01,		//等于
	enmCompareOperator_Gt				= 0x02,		//大于
	enmCompareOperator_Lt				= 0x03,		//小于
	enmCompareOperator_GE				= 0x04,		//大于等于
	enmCompareOperator_LE				= 0x05,		//小于等于
	enmCompareOperator_Ue				= 0x06,		//不等于
};

typedef uint32_t LoginResult;
enum
{
	enmLoginResult_OK = 0x00,
	enmLoginResult_AccountLock = 0x01,
	enmLoginResult_IpLock = 0x02,
	enmLoginResult_MacLock = 0x03,
	enmLoginResult_Timeout = 0x04,
	enmLoginResult_VerError = 0x05,
	enmLoginResult_Unknown = 0xff,
};

typedef uint32_t KickReason;
enum
{
	enmKickReason_Relogin = 0x00, //重复登陆
	enmKickReason_SendAd = 0x01, //发送广告
	enmKickReason_PlayerLock = 0x10,	//玩家被封
	enmKickReason_IPLock = 0x11,	//IP被封
	enmKickReason_MacLock = 0x12,	//Mac被封
	enmKickReason_Other = 0xff,
};


typedef uint32_t ChangeResult;
enum
{
	enmChangeResult_OK = 0x00,
	enmChangeResult_NO_PERMISSION = 0x01, //没有权限
	enmChangeResult_Is_Full = 0x02, //被设置的管理已满
	enmChangeResult_Is_AdminInOther = 0x03, //在其他的房间有管理权限
	enmChangeResult_UNKNOWN = 0xff,

};

//状态定义
typedef uint16_t					PlayerState;
enum
{
	enmInvalidPlayerState				= 0x00,		//无效值
	enmPlayerState_InHall				= 0x01,		//在大厅
	enmPlayerState_InRoom				= 0x02,		//在房间
	enmPlayerState_PublicMic			= 0x03,		//公麦
	enmPlayerState_PublicMicQueue		= 0x04,		//公麦序
	enmPlayerState_PrivateMic			= 0x05,		//私麦
	enmPlayerState_PrivateMicQueue		= 0x06,		//私麦序
	enmPlayerState_P2PMic				= 0x07,     //一对一麦上
	enmPlayerState_P2PMicAndMicQueue	= 0x08,     //一对一麦且麦序
};

typedef uint16_t					StatusType;
enum
{
	enmInvalidStatusType           = 0x00,		//无效值
	enmStatusType_PUBLIC_1		 	= 0x01, //1号公麦
	enmStatusType_PUBLIC_2 			= 0x02, //2号公麦
	enmStatusType_PUBLIC_3 			= 0x04, //3号公麦
	enmStatusType_PRIVATE 			= 0x08, //私麦
	enmStatusType_P2P 				= 0x10, //一对一视频
	enmStatusType_FORBIDDEN 		= 0x20, //被禁言
	enmStatusType_VIDEO 			= 0x40, //视频打开
	enmStatusType_AUDIO 			= 0x80,
//音频打开
};


//在房间的管理权限
typedef uint16_t					RoleRank;
enum
{
	enmRoleRank_None				= 0x00,		//无权限
	enmRoleRank_TempAdmin			= 0x01,		//临时管理员
	enmRoleRank_Admin				= 0x02,		//管理员
	enmRoleRank_MinorHost			= 0x04,		//副室主
	enmRoleRank_Host				= 0x08,		//室主
	enmRoleRank_Super				= 0x10,		//超级管理员（运营）

};

//广播消息的类型
typedef uint8_t						BroadcastType;
enum
{
	enmBroadcastType_All			= 0x00,		//房间内的所有人
	enmBroadcastType_ExceptPlayr	= 0x01,		//除某个玩家之外的所有玩家
	enmBroadcastType_ExpectPlayr	= 0x02,		//发送通知给指定玩家
	enmBroadcastType_ExceptRoom		= 0x03,		//除某个房间外的所有人
};

//房间自由排麦关闭情况
typedef uint8_t						FreeShowOpenedType;
enum
{
	enmFreeShowOpenedType_Close			= 0x00,		//打开
	enmFreeShowOpenedType_Open	        = 0x01,		//关闭
};

//房间自由排麦关闭情况
typedef uint8_t						PrivateMicOpenedType;
enum
{
	enmPrivateMicOpenedType_Close			= 0x00,		//打开
	enmPrivateMicOpenedType_Open	        = 0x01,		//关闭
};


////网络类型
//typedef uint8_t							NetType;
//enum
//{
//	enmNetType_Tel						= 0x00,			//电信
//	enmNetType_Cnc						= 0x01,			//网通
//	enmNetType_Count					= 0x02,
//};

//av状态类型
typedef uint8_t						AVType;
enum
{
	enmAVType_Open						= 0x00,			//打开
	enmAVType_Close						= 0x01,			//关闭
};

typedef uint32_t					AssetType;
enum
{
	enmInvalidAssetType					= 0x00,
	enmAssetType_Money					= 0x00000001,	//更新玩家的钱
	enmAssetType_Count					= 0x00000002,	//资产类型的数量
	enmAssetType_GoldCoin               = 0x00000003,   //金豆
	enmAssetType_SpendMoneySum			= 0x00000004,	//玩家总花费
};

typedef uint8_t						UpdateAssetOperate;
enum
{
	enmInvalidUpdateAssetOperate		= 0x00,
	enmUpdateAssetOperate_Increase		= 0x01,			//添加
	enmUpdateAssetOperate_Reduce		= 0x02,			//减少
};

typedef uint32_t					CauseID;
enum
{
	enmInvalidCauseID					= 0x00,
	enmCauseID_SpendItem				= 0x00000001,	//购买道具扣费
	enmCauseID_ItemProfit				= 0x00000002,	//来自于道具的提成
	enmCauseID_UseItem					= 0x00000003,	//使用道具(如盖章)
	enmCauseID_ItemTimeout				= 0x00000004,	//道具超时
	enmCauseID_LuckyProfit				= 0x00000005,	//幸运中奖
	enmCauseID_GodWealthProfit			= 0x00000006,	//请出财神的奖励
	enmCauseID_GodWealthAndItemProfit	= 0x00000007,	//降财神的奖励和道具收益
	enmCauseID_GoodExpire				= 0x00000008,	//物品过期
	enmCauseID_FromGameServer			= 0x00000009,	//来自gameserver的加减币请求
	enmCauseID_RequestSong				= 0x0000000a,	//请求点歌
	enmCauseID_AcceptRequestSong		= 0x0000000b,	//接受点歌
	enmCauseID_RefuseRequestSong		= 0x0000000c,	//拒绝点歌
};

typedef int32_t						UpdateUserAsset;
enum
{
	enmUpdateUserAsset_OK				= 0x00000000,
	enmUpdateUserAsset_NotEnoughMoney	= 0x00000001,	//钱不够
	enmUpdateUserAsset_DestNotFound		= 0x00000002,	//目标玩家没有找到
	enmUpdateUserAsset_Timeout			= 0x00000003,	//超时
	enmUpdateUserAsset_Unknown			= 0x00000004,	//未知错误
};

typedef uint8_t						ItemType;
enum
{
	enmInvalidItemType					= 0x00,
	enmItemType_Normal					= 0x01,			//普通
	enmItemType_Luxury					= 0x02,			//奢侈
	enmItemType_Lucky					= 0x03,			//幸运
	enmItemType_Stamp					= 0x04,			//印章
	enmItemType_GodOfWealth				= 0x05,			//财神
	enmItemType_Firework				= 0x06,			//烟花
	enmItemType_SaultingGun				= 0x07,			//礼炮
	enmItemType_LoudSpeaker				= 0x08,			//喇叭
	enmItemType_ChooseSong				= 0x09,			//浪漫点歌
	enmItemType_BlinkEnter				= 0x0a,			//闪亮登场
	enmItemType_ChangeVoice				= 0x0b,			//变声卡
	enmItemType_FlyWords				= 0x0c,			//飞屏
	enmItemType_Sofa					= 0x0d,			//沙发
	enmItemType_RequestSong				= 0x0e,			//点歌
};

typedef uint8_t						UpdateItemOperate;
enum
{
	enmInvalidUpdateItemOperate			= 0x00,
	enmUpdateItemOperate_Add			= 0x01,			//增加
	enmUpdateItemOperate_Update			= 0x02,			//更新
	enmUpdateItemOperate_Del			= 0x03,			//删除
};

typedef uint8_t						LoudSpeakerType;
enum
{
	enmLoudSpeakerType_Small			= 0x00,
	enmLoudSpeakerType_Big				= 0x01,
	enmLoudSpeakerType_Super			= 0x02,
};

typedef uint8_t						SpeakerMessageType;
enum
{
	enmSpeakerMessageType_Loud			= 0x00,			//喇叭消息
	enmSpeakerMessageType_Lucky			= 0x01,			//幸运物品中500，1000倍消息
	enmSpeakerMessageType_System		= 0x02,			//系统公告消息
	enmSpeakerMessageType_GodWealth		= 0x03,			//天降财神消息
	enmSpeakerMessageType_GameReward    = 0x04,         //游戏中奖消息
	enmSpeakerMessageType_Luxury		= 0x05,			//奢侈品消息
};

//class ConnUin
//{
//public:
//	uint8_t					nVersion;				//版本
//	uint8_t					nServerID;				//tunnel server的id
//	uint16_t				nTunnelIndex;			//tunnel server的内部索引
//	int32_t					nRoleID;				//用户id
//	int32_t					nCreateTime;			//连接创建时间
//	uint32_t				nIsn;					//序列号,由tunnel server分配
//	uint32_t				nAddress;				//ip
//	uint16_t				nPort;					//端口
//	NetType					nNetType;				//标示客户端的网络类型
//
//	ConnUin()
//	{
//		Reset();
//	}
//
//	void Reset()
//	{
//		nVersion		= 0;
//		nServerID		= 0;
//		nTunnelIndex	= 0;
//		nRoleID			= -1;
//		nCreateTime		= 0;
//		nIsn			= 0;
//		nAddress		= 0;
//		nPort			= 0;
//		nNetType		= enmNetType_Tel;
//	}
//};

//最大/最小值定义
#if defined(DEBUG) || defined(_DEBUG) || defined(_DEBUG_)
#define MaxTokenBuffSize				2048
//最大账号长度
#define	MaxAccountName					32
//房间名称最大长度
#define MaxRoomNameLength				64
//频道名称最大长度
#define MaxChannelNameLength			128
//分区名称最大长度
#define MaxRegionNameLength				64
//一个房间最大容纳用户数量
#define MaxUserCountPerRoom				1300
//房间的用户桶大小
#define RoomPlayerBucketSize			((MaxUserCountPerRoom) * 4)
//一个房间最大容纳管理员数量
#define MaxAdminCountPerRoom			520
//房间的管理员桶大小
#define RoomAdminBucketSize				((MaxAdminCountPerRoom) * 4)
//一个频道最大的房间数量
#define MaxRoomCountPerChannel			200
//频道的房间桶大小
#define ChannelBucketSize				((MaxRoomCountPerChannel) * 4)
//一个大区最多的频道数量
#define MaxChannelCountPerRegion		32
//一个服务器最大的频道对象数
#define MaxChannelCountPerServer		32
//一个服务器最大的玩家对象数
#define MaxPlayerCountPerServer			10000
//一个服务器最大的房间数
#define MaxRoomCountPerServer			500
//默认展示的房间用户上限值
#define MaxDefaultShowUserLimit			300
//真实的房间用户上限值
#define MaxDefaultRealUserLimit			500
//最多的分区数
#define MaxRegionCount					32
//可以同时进入的房间数
#define MaxEnterRoomCount				12
//最大的字符串长度
#define MaxStringLength					65535
//用户昵称的最大长度
#define MaxRoleNameLength				64
//用户被踢原因的最大长度
#define MaxKickedReasonLength			128
//最大的房间数
#define MaxRoomCount					50
//最大的mediaserver数
#define MaxMediaCount					50
//房间桶大小
#define RoomBucketSize					((MaxRoomCount) * 4)
//最大的server数（每一种服务器）
#define MaxServerCount					32
//最大在线人数
#define MaxOnlinePlayerCount			1000
//最大的转发数量
#define MaxTransmitUserCount			MaxUserCountPerRoom
//最大的房间密码长度
#define MaxRoomPasswordLength			32
//黑名单最大人数
#define MaxRoomBlackListSize			1000
//禁言名单最大人数
#define MaxRoomProhibitSpeakSize		2
//被封IP最大数量
#define MaxRoomLockIP					1000
//一个服务器最大的消息头数量
#define MaxMsgHeadCountPerServer        10000
//踢出名单最大人数
#define MaxRoomKickListSize				1000
//最大房间签名长度
#define MaxRoomSignatureSize			512
//最多是多少个房间的管理员
#define MaxBeAdminPerPlayer				32
//最大的文本长度
#define MaxTextMessageSize				1024
//fonttype的字符串长度
#define MaxFontTypeStringSize			512
//房间公麦最大数量
#define MaxPublicMicCount				3
//房间排麦数量
#define MaxWaittingMicCount				50
//房间私麦数量
#define MaxPrivateMicCount				MaxAdminCountPerRoom
//每次踢人最大个数
#define MaxPerKickCount				    200
//每个mediaserver上最大的房间数
#define MaxRoomCountPerMedia			1000
//道具名字最大长度
#define MaxItemNameSize					64
//一次可以设置的房间信息个数
#define MaxSetRoomTypeCount				4
//一次可以获取的房间信息个数
#define MaxGetRoomTypeCount				12
//房间设置字符串最大长度
#define MaxSetRoomTextSize				1024
//房间公告最大值
#define MaxRoomNoticeLength				1024
//房间主题最大值
#define MaxRoomSignatureLength			512
//房间欢迎词最大值
#define MaxRoomWelcomeLength			1024
//最大的幸运中奖次数
#define MaxLuckyCount					100
//最大的在玩家身上使用的Item的数量
#define MaxOnUserItemCount				32
//最大的在玩家身上物品数量
#define MaxPlayerGoodsCount				32
//一次最大可更新的资产数量
#define MaxUpdateAssetCount				32
//一次最大可更新多少用户的资产
#define MaxBatchUpdateRoleAssetCount	1000
//最大的道具种类
#define MaxItemKindCount				0xffff
//机器人发送彩条的定时器超时时间（秒）
#define RobotSendColorTimeOut			1
//财神降临最大次数
#define MaxDefallCount					10
//幸运物品所能有的最大奖池数
#define MaxJackpotCountPerLuckyItem		8
//封玩家理由字符串的最大长度
#define MaxLockPlayerReasonLength		128
//踢玩家理由字符串的最大长度
#define MaxKickPlayerReasonLength		128
//登录失败理由字符串的最大长度
#define MaxLoginFailReasonLength		128
//一次所能获取的最大奖池信息个数
#define MaxGetJackpotInfoCount			10
//封锁房间里有字符串的最大长度
#define MaxLockRoomReasonLength         128
//开通房间提示信息最大长度
#define MaxLaunchRoomNoticeLength       128
//最大更新数据大小
#define MaxUpdateDataSize				1024 * 8
//一次最多重建玩家数据的个数
#define MaxBuildPlayerDataCount			10
//一次最多重建房间数据的个数
#define MaxBuildRoomDataCount			10
//一个房间数据所占的内存大小
#define RoomCacheSize					1024 * 200
//一个大厅房间数据所占的内存大小
#define HallRoomCacheSize				200
//一个玩家数据所占的内存大小
#define PlayerCacheSize					1024 * 20
//roomdispatcher管理的最大roomserver数量
#define MaxRoomServerCountPerRoomDispatcher	12
//一玩家同时获得的礼物之星的个数
#define MaxGiftStarCount				32
//一次可获取的在线玩家大小
#define MaxGetOnlinePlayerCount			100
//飞屏内容大小
#define MaxFlyWordsMessageSize			512
//mac字符串长度
#define MaxMacAddrStringLength			32
//封IP原因的最大长度
#define MaxLockIPReasonLength           MaxLockPlayerReasonLength
//每次封停的最大个数
#define MaxLockCountOnce   100
//最大的封停内容的长度
#define MaxLockContentLength            128
//更新资产失败原因的最大长度
#define MaxAssetUpdateFailReasonLength  512
//最大的客户端请求失败原因
#define MaxReqFailReasonLength  		128
//最大的观看私麦的数量
#define MaxWatchPrivateMicCount			10
//一个房间类型服务器最大的玩家数量
#define MaxPlayerCountPerRoomServer		150
//从后台批量获取玩家在线情况的最大玩家数量
#define MaxGetPlayerOnlineStatusNum		50
//资产更新原因的最大长度
#define MaxAssetUpdateReasonLength      512
//用户网络环境统计key值的最大长度
#define MaxRoomCollectionKeyLen         128
//用户网络环境统计内容值的最大长度
#define MaxRoomCollectionContentLen   512
//用户网络环境统计数量最大值【每一次】
#define MaxRoomCollectionInfoCount  100
//每个用户所能拥有的最多的成就的个数
#define MaxAchieveCount  10
//网络状况统计内容中字段最多个数
#define MaxFieldCountInNetStatus       10
//网络状况统计中每个字段的最大长度
#define MaxFieldLenInNetStatus         50
//当前网络状况统计内容中字段的个数: netname + media + ip + lost_ratio
#define CurFieldCountInNetStatus       4
//网络类型的最大长度
#define MaxNetTypeLen  64
//最大的频道号
#define MaxChannelID  1000000000
//每种排行榜最多人数
#define MaxFansCountPerType   5
//每个消息最多可以发送给多少个server
#define MAX_DST_SERVER_COUNT 32
//每个server的消息配置文件中最多有多少行
#define MaxMsgCount 128
//字段对应的字符串的最大长度
#define MaxFieldStringLen 1024
//客户端游戏名称的最大程度
#define MaxGameNameLength  256
//获取用户兑换记录的最大条数【每次最多能获取多少条】
#define MaxExchangeLogCountPerTime 128
//歌曲名最大长度
#define MaxSongNameLength				256
//每位歌手的歌单最多的歌曲数
#define MaxSongCountPerPlayer			50
//艺人歌曲列表管理器容量
#define MaxSongListMgtSize				2000
//艺人最多的热推歌曲数
#define MaxHotSongCountPerPlayer		5
//祝福语最大的长度
#define MaxWishWordsLength				512
//最大投票票数
#define MaxVoteTicketsCount				32
//用户头像连接最大长度
#define MaxThumbLength                  255
//房间最大艺人数
#define MAX_ARTIST_NUM                  200
//最多收藏房间数据
#define MaxCollectCount					50
//最大缓存的账号池数量
#define MaxCacheUnusedAccountCount		1000
#else
#define MaxTokenBuffSize				2048
//最大账号长度
#define	MaxAccountName					32
//房间名称最大长度
#define MaxRoomNameLength				64
//频道名称最大长度
#define MaxChannelNameLength			128
//分区名称最大长度
#define MaxRegionNameLength				64
//一个房间最大容纳用户数量
#define MaxUserCountPerRoom				1300
//房间的用户桶大小
#define RoomPlayerBucketSize			((MaxUserCountPerRoom) * 4)
//一个房间最大容纳管理员数量
#define MaxAdminCountPerRoom			520
//房间的管理员桶大小
#define RoomAdminBucketSize				((MaxAdminCountPerRoom) * 4)
//一个频道最大的房间数量
#define MaxRoomCountPerChannel			1024
//频道的房间桶大小
#define ChannelBucketSize				((MaxRoomCountPerChannel) * 4)
//一个大区最多的频道数量
#define MaxChannelCountPerRegion		128
//一个服务器最大的频道对象数
#define MaxChannelCountPerServer		128
//一个服务器最大的玩家对象数
#define MaxPlayerCountPerServer			10000
//一个服务器最大的房间数
#define MaxRoomCountPerServer			1024
//默认展示的房间用户上限值
#define MaxDefaultShowUserLimit			300
//真实的房间用户上限值
#define MaxDefaultRealUserLimit			500
//最多的分区数
#define MaxRegionCount					32
//可以同时进入的房间数
#define MaxEnterRoomCount				12
//最大的字符串长度
#define MaxStringLength					65535
//用户昵称的最大长度
#define MaxRoleNameLength				64
//用户被踢原因的最大长度
#define MaxKickedReasonLength			128
//最大的房间数
#define MaxRoomCount					20000
//最大的mediaserver数
#define MaxMediaCount					2000
//房间桶大小
#define RoomBucketSize					((MaxRoomCount) * 4)
//最大的server数（每一种服务器）
#define MaxServerCount					32
//最大在线人数
#define MaxOnlinePlayerCount			100000
//最大的转发数量
#define MaxTransmitUserCount			MaxUserCountPerRoom
//最大的房间密码长度
#define MaxRoomPasswordLength			32
//黑名单最大人数
#define MaxRoomBlackListSize			1000
//禁言名单最大人数
#define MaxRoomProhibitSpeakSize		1000
//被封IP最大数量
#define MaxRoomLockIP					1000
//一个服务器最大的消息头数量
#define MaxMsgHeadCountPerServer        10000
//踢出名单最大人数
#define MaxRoomKickListSize				1000
//最大房间签名长度
#define MaxRoomSignatureSize			512
//最多是多少个房间的管理员
#define MaxBeAdminPerPlayer				32
//最大的文本长度
#define MaxTextMessageSize				1024
//fonttype的字符串长度
#define MaxFontTypeStringSize			512
//房间公麦最大数量
#define MaxPublicMicCount				3
//房间排麦数量
#define MaxWaittingMicCount				50
//房间私麦数量
#define MaxPrivateMicCount				MaxAdminCountPerRoom
//每次踢人最大个数
#define MaxPerKickCount				    200
//每个mediaserver上最大的房间数
#define MaxRoomCountPerMedia			1000
//道具名字最大长度
#define MaxItemNameSize					64
//一次可以设置的房间信息个数
#define MaxSetRoomTypeCount				4
//一次可以获取的房间信息个数
#define MaxGetRoomTypeCount				12
//房间设置字符串最大长度
#define MaxSetRoomTextSize				1024
//房间公告最大值
#define MaxRoomNoticeLength				1024
//房间主题最大值
#define MaxRoomSignatureLength			512
//房间欢迎词最大值
#define MaxRoomWelcomeLength			1024
//最大的幸运中奖次数
#define MaxLuckyCount					100
//最大的在玩家身上使用的Item的数量
#define MaxOnUserItemCount				32
//最大的在玩家身上物品数量
#define MaxPlayerGoodsCount				32
//一次最大可更新的资产数量
#define MaxUpdateAssetCount				32
//一次最大可更新多少用户的资产
#define MaxBatchUpdateRoleAssetCount	2000
//最大的道具种类
#define MaxItemKindCount				0xffff
//机器人发送彩条的定时器超时时间（秒）
#define RobotSendColorTimeOut			1
//财神降临最大次数
#define MaxDefallCount					10
//幸运物品所能有的最大奖池数
#define MaxJackpotCountPerLuckyItem		8
//封玩家理由字符串的最大长度
#define MaxLockPlayerReasonLength		128
//踢玩家理由字符串的最大长度
#define MaxKickPlayerReasonLength		128
//登录失败理由字符串的最大长度
#define MaxLoginFailReasonLength		128
//一次所能获取的最大奖池信息个数
#define MaxGetJackpotInfoCount			10
//封锁房间里有字符串的最大长度
#define MaxLockRoomReasonLength         128
//开通房间提示信息最大长度
#define MaxLaunchRoomNoticeLength       128
//最大更新数据大小
#define MaxUpdateDataSize				1024 * 8
//一次最多重建玩家数据的个数
#define MaxBuildPlayerDataCount			10
//一次最多重建房间数据的个数
#define MaxBuildRoomDataCount			10
//一个房间数据所占的内存大小
#define RoomCacheSize					1024 * 200
//一个大厅房间数据所占的内存大小
#define HallRoomCacheSize				200
//一个玩家数据所占的内存大小
#define PlayerCacheSize					1024 * 20
//roomdispatcher管理的最大roomserver数量
#define MaxRoomServerCountPerRoomDispatcher	12
//一玩家同时获得的礼物之星的个数
#define MaxGiftStarCount				32
//一次可获取的在线玩家大小
#define MaxGetOnlinePlayerCount			100
//飞屏内容大小
#define MaxFlyWordsMessageSize			512
//mac字符串长度
#define MaxMacAddrStringLength			32
//封ip原因字符串的大小
#define MaxLockIPReasonLength           MaxLockPlayerReasonLength
//每次封停的最大个数
#define MaxLockCountOnce   100
//最大的封停内容的长度
#define MaxLockContentLength            32
//更新资产失败原因的最大长度
#define MaxAssetUpdateFailReasonLength  512
//最大的客户端请求失败原因
#define MaxReqFailReasonLength  		128
//最大的观看私麦的数量
#define MaxWatchPrivateMicCount			30
//一个房间类型服务器最大的玩家数量
#define MaxPlayerCountPerRoomServer		10000
//从后台批量获取玩家在线情况的最大玩家数量
#define MaxGetPlayerOnlineStatusNum		50
//资产更新原因的最大长度
#define MaxAssetUpdateReasonLength      512
//用户网络环境统计key值的最大长度
#define MaxRoomCollectionKeyLen         128
//用户网络环境统计内容值的最大长度
#define MaxRoomCollectionContentLen   512
//用户网络环境统计数量最大值【每一次】
#define MaxRoomCollectionInfoCount  100
//每个用户所能拥有的最多的成就的个数
#define MaxAchieveCount  10
//网络状况统计内容中字段最多个数
#define MaxFieldCountInNetStatus       10
//网络状况统计中每个字段的最大长度
#define MaxFieldLenInNetStatus         50
//当前网络状况统计内容中字段的个数: netname + media + ip + lost_ratio
#define CurFieldCountInNetStatus       4
//网络类型的最大长度
#define MaxNetTypeLen  64
//最大的频道号
#define MaxChannelID  1000000000
//每种排行榜最多人数
#define MaxFansCountPerType   5
//每个消息最多可以发送给多少个server
#define MAX_DST_SERVER_COUNT 32
//每个server的消息配置文件中最多有多少行
#define MaxMsgCount 128
//字段对应的字符串的最大长度
#define MaxFieldStringLen 1024
//客户端游戏名称的最大程度
#define MaxGameNameLength  256
//获取用户兑换记录的最大条数【每次最多能获取多少条】
#define MaxExchangeLogCountPerTime 128
//歌曲名最大长度
#define MaxSongNameLength	256
//每位歌手的歌单最多的歌曲数
#define MaxSongCountPerPlayer			50
//艺人歌曲列表管理器容量
#define MaxSongListMgtSize				2000
//艺人最多的热推歌曲数
#define MaxHotSongCountPerPlayer		5
//祝福语最大的长度
#define MaxWishWordsLength				512
//最大投票票数
#define MaxVoteTicketsCount				32
//用户头像连接最大长度
#define MaxThumbLength                  255
//房间最大艺人数
#define MAX_ARTIST_NUM                  200
//最多收藏房间数据
#define MaxCollectCount					50
//最大缓存的账号池数量
#define MaxCacheUnusedAccountCount		100000
#endif

//最大值枚举定义
enum
{
	enmMaxSerialNumberLength		= 40,	//流水号最大长度
	enmMaxTimeStringLength			= 128,	//最大时间描述字符串
};

//无效值定义
enum
{
	enmInvalid16BitsIndex		= 0xffff,
	enmInvalid32BitsIndex		= 0xffffffff,
	enmInvalid16BitsValue		= 0xffff,
	enmInvalid32BitsValue		= 0xffffffff,
};


//默认值定义



//vvip等级
typedef uint8_t					VipLevel;
enum 
{
	enmVipLevel_NONE 				= 0x00, //未注册
	enmVipLevel_Regist	 			= 0x01, //已注册
	enmVipLevel_Gold 				= 0x02, //黄金vip
	enmVipLevel_Diamond 			= 0x04, //钻石vip
	enmVipLevel_Baron 				= 0x08, //男爵
	enmVipLevel_Viscount 			= 0x10, //子爵
	enmVipLevel_Earl 				= 0x20, //伯爵
	enmVipLevel_Marquis 			= 0x40, //侯爵
	enmVipLevel_Duke 				= 0x60, //公爵
	enmVipLevel_King 				= 0x80, //国王
};

//用户等级
typedef uint8_t					UserLevel;


//服务器类型
enum
{
	enmEntityType_None				= 0x00,				//无效值

	enmEntityType_Example			= 0x01,				//样例服务器
	enmEntityType_Router			= 0x02,				//路由器
	enmEntityType_Connect			= 0x03,				//网络连接服务器
	enmEntityType_Hall				= 0x04,				//大厅服务器
	enmEntityType_Media				= 0x05,				//媒体服务器
	enmEntityType_Tunnel			= 0x06,				//后端网络服务器
	enmEntityType_Room				= 0x07,				//房间服务器
	enmEntityType_Item				= 0x08,				//道具服务器
	enmEntityType_DBProxy			= 0x09,				//数据库代理服务器， 专门做写服务
	enmEntityType_WebConn           = 0x0A,             //web连接服务器
	enmEntityType_Webagent          = 0x0B,             //与官网交互的代理服务器(主要功能为web与后端server之间的协议转换)
	enmEntityType_Account			= 0x0C,				//账号注册服务器
	enmEntityType_SysInfo			= 0x0D,				//系统消息服务器
	enmEntityType_Daemon			= 0x0E,				//守护精灵
	enmEntityType_RoomDispatcher	= 0x10,				//房间分发服务器
	enmEntityType_DBProxyRead       = 0x11,             //专门做读服务的dbproxy
	enmEntityType_Task              = 0x12,             //任务服务器
	enmEntityType_NewWebConn        = 0x13,             //新版web连接服务器, 十进制为19
	enmEntityType_HallDataCenter    = 0x14,             //大厅数据备份服务器
	enmEntityType_ClientGame        = 0x15,             //客户端游戏服务器
	enmEntityType_Transmiter		= 0x16,				//媒体中转服务器
	enmEntityType_AccountAgent		= 0x17,				//帐号代理服务器
	enmEntityType_OptGate			= 0x18,				//运营后台网关服务器

	enmEntityType_Count				= 0x18,				//服务器类型个数
	enmEntityType_Client			= 0x80,				//客户端
	enmEntityType_Web				= 0x81,				//web客户端
};

//原因定义
typedef uint8_t					LogoutReason;
enum
{
	enmLogoutReason_Unknown			= 0x00,				//未知
	enmLogoutReason_ClientRequest	= 0x00,				//客户端主动退出
	enmLogoutReason_ClientDisconnect= 0x01,				//客户端掉线
	enmLogoutReason_Relogin			= 0x02,				//重复登陆
	enmClientCloseReason_Tunnel_RecvStartRequestWhenUse = 102, //连接对象收到的第一个包的时候已经是被使用状态，见TunnelServer文档
};

typedef uint8_t					UserStatus;
enum
{
	enmInvalidUserStatus		= 0x00,
};

typedef uint8_t					ModifyType;
enum
{
	enmInvalidModifyType		= 0x00,
	enmAudioModifyType			= 0x01,
	enmVedioModifyType			= 0x02,
};

typedef uint8_t					ModifyValue;
enum
{
	enmInvalidModifyValue		= 0x00,
	enmOpenModifyValue			= 0x01,
	enmCloseModifyValue			= 0x02,
};

typedef int32_t					PlaceID;
enum
{
	enmInvalidPlaceID			= -1
};
typedef uint8_t					OperateAVType;
enum
{
	OPERATEAVTYPE_OPEN_VIDEO		=	0x00,
	OPERATEAVTYPE_OPEN_AUDIO		=	0x01,
	OPERATEAVTYPE_CLOSE_VIDEO		=	0x02,
	OPERATEAVTYPE_CLOSE_AUDIO		=	0x03,
};

//答复一对一视频请求
typedef uint8_t					ResponseP2PType;
enum
{
	enmRESPONSEP2PTYPE_ACCEPT			=	0x00,  //接受
	enmRESPONSEP2PTYPE_REFUSE			=	0x01,  //拒绝
};

////物品的使用方式
//typedef uint8_t   UseMeans;
//enum
//{
//	enmUseMeans_None                   = 0x00,   //无效的使用方式
//	enmUseMeans_Time                   = 0x01,   //计时使用
//	enmUseMeans_Count                  = 0x02,   //计数使用
//	enmUseMeans_Trig                   = 0x03,   //触发使用
//};

//资产更新渠道
typedef uint8_t AssetUpdateChannel;
enum
{
	enmAssetUpdateChannel_None              = 0x00,   //无效的资产更新渠道
	enmAssetUpdateChannel_Recharge          = 0x01,   //充值
	enmAssetUpdateChannel_Add               = 0x02,   //运营人员直接给玩家加钱
	enmAssetUpdateChannel_RoomHostGet       = 0x03,    //室主领取贡献
	enmAssetUpdateChannel_RoomHost179Plant  = 0x04,  //室主179币种花
	enmAssetUpdateChannel_RoomHostSongReq   = 0x05,  //室主使用点歌小七种花
	enmAssetUpdateChannel_Artist179Plant    = 0x06,   //艺人用179币种花
	enmAssetUpdateChannel_ArtistSongReq     = 0x07,   //艺人用点歌小七种花
	enmAssetUpdateChannel_Contribution      = 0x08,   //管理员后台领取贡献， 无需客户端右下角弹框
	enmAssetUpdateChannel_Reward            = 0x09,   //推荐人获得充值返利, B推荐A， 然后A充了值，此时，B会获得一定的179币
	enmAssetUpdateChannel_PayReward         = 0x0A,   //充值达到一定金额获得返利
	enmAssetUpdateChannel_UpgradeReward     = 0x0B,   //升级获得赠送的币
	enmAssetUpdateChannel_TaskChargeReward	= 0x0C,		//任务系统首次充值获得奖励
	enmAssetUpdateChannel_GameReward        = 0x0d,    //游戏奖励
};

//最大值定义
enum
{
	enmMaxRoomIDSBufLength 			= 512,         //user_base_info表中的roominfo字段的最大长度
	enmMaxRoomIDStringLength 		= 16,        //整型的roomid对应的字符串的最大长度
	enmMaxUserOwnRoomCount   		= 128,       //玩家拥有的房间最多个数
	enmMaxToRoleCount        		= 800,      //礼物可以同时送给多少人
	enmMaxRoleBaseInfoBufLen 		= 1024 * 16,    //玩家基本信息缓冲区的最大长度
	enmMaxRoomBaseInfoBufLen 		= 1024,    //玩家基本信息缓冲区的最大长度
	enmMaxBillTransIDLen     		= 128,     //账单流水号的最大长度
	enmMaxProvinceNameLength        = 32,    //最大省份名称长度
	enmMaxCityNameLength            = 32,    //最大市名长度
	enmMaxCountyNameLength          = 32,    //最大县名长度
	enmMaxAddrLength                = 32 * 3, //最大地名长度
	enmMaxHoroScopeNameLength       = 32,     //最大星座名称长度
	enmMaxEmailAddrLength           = 32,     //最大邮箱地址长度
	enmMaxPasswordLength			= 32,	  //最大密码长度
	enmMaxPassportLength			= 64,	  //最大登录口令长度
	enmMaxPlatformLength			= 64,	  //最大平台名字长度
	enmMaxChannelIDLength			= 32,	  //最大的渠道号长度
	enmMaxTelephoneLength           = 16,     //手机号码最大长度
	enmMaxQQLength                  = 16,     //QQ号码的最大长度
	enmMaxAccountSrcLength          = 32,     //账户来源最大长度
	MaxRoleIDStringLength           = 16,     //roleid对应的字符串的最大长度
	enmMaxWelcomewordsLength        = 128,    //房间欢迎词的最大长度
	enmMaxRegionNameLength          = 32,     //最大的区域名称长度
	enmMaxAccountTypeLength         = 16,     //账号类型对应的字符串的最大长度
	enmMaxRoleIDStringLength        = 32,     //roleid对应的字符串的最大长度
	enmMinMessageSize               = 1024,      //为了dump比较小的消息（比如只有几个整数类型的字段，为节约栈空间）而设置此值
	enmNormalMessageSize            = 1024 * 8, //最大的正常的消息的长度（因为之前用的是enmMaxMessageSize， 这个值是256K，
  											    //过于庞大，为了节省内存，出此下策，对于不太大的消息，可以用这个来作为消息的大小）
	enmMaxPlayerMoney               =  4000000000,   //玩家的钱的最大数量，40亿币， 对应人民币 400万
};

typedef uint8_t RoomInfoType;
enum
{
	enmRoomInfoType_NAME			    =	0x00, //string房间名字
	enmRoomInfoType_SIGNATURE			=	0x01, //string 房间主题
	enmRoomInfoType_PASSWORD			=	0x02, //string(空串即没有密码)
	enmRoomInfoType_FREESHOW_TIME		=	0x03, //uint8(自由排麦时上麦时间,min)
	enmRoomInfoType_WELCOME_WORDS		=	0x04, //string(欢迎词)
	enmRoomInfoType_NOTICE				=	0x05, //string(公告)
	enmRoomInfoType_OPTION				=	0x06, //uint32(RoomOptionType)
	enmRoomInfoType_Mic_First_Status	=   0x07,
	enmRoomInfoType_Mic_Second_Status	=   0x08,
	enmRoomInfoType_Mic_Third_Status	=   0x09,
	enmRoomInfoType_Count				=   0x0a,  //用于得到现在房间设置分为几大部分
};


//房间配置
typedef uint32_t				RoomOptionType;
enum
{
	enmRoomOptionType_Room_Close				= 0x0000001,        //房间处于关闭状态
	enmRoomOptionType_Public_Chat_Vip         = 0x0000002,        //vip可以公聊
	enmRoomOptionType_Color_Text_Close          = 0x0000004,        //彩条关闭
	enmRoomOptionType_User_InOut_Open           = 0x0000008,        //用户进出信息打开
	enmRoomOptionType_FreeShow_Open	       	    = 0x0000010,		//自由排麦处于打开状态
	enmRoomOptionType_FreeShow_ForManager_Close	= 0x0000020,		//限制管理员卖时
	enmRoomOptionType_FreeShow_Edit_Time_Close	= 0x0000040,		//管理员不可以修改麦时
	enmRoomOptionType_Has_PrivateMic			= 0x0000080,		//有私麦
	enmRoomOptionType_PrivateMIC_Close			= 0x0000100,		//私麦处于关闭状态
	enmRoomOptionType_Auto_Welcome_Close		= 0x0000200,		//自动欢迎关闭
	enmRoomOptionType_Show_RoomName_Close		= 0x0000400,		//()
};

//系统消息定义
#define MaxInfoSize		1024
#define MaxTitleSize	64
#define MaxNotiCount	10
#define UserCountEveryTime 100
#define MaxDegradeCountEveryTime 1000//批量降级的count宏 ,1.7版本临时改
#define MaxRankListTypes 50
#define MaxMsgContentLen 1024
#define MaxGetMsgCount 	50
#define MaxNoticeTitleLen 32
#define MaxNoticeCount 50
#define MaxGetOnlinePlayerLefMoneyCount	500
#define MaxIdentityCount	32
#define MaxItemMsgLength	256
#define MaxPerGetRoomSofaCount		500
#define ROOM_SOFACOUNT	5	//单个房间的沙发个数

//ItemServer定义
#define MaxPerGetLuckyUserCount	100 //单次取得幸运中奖玩家的个数

typedef uint8_t  				PlayerType;
enum
{
	enmPlayerType_Normal			    =	0x00, //正常的
	enmPlayerType_Rebot					=	0x01, //机器人
};

typedef uint16_t 				UserClientInfo;
enum
{
	enmUserClientInfo_PC			    	=	0x00, //PC用户
	enmUserClientInfo_Web					=	0x01, //Web用户
	enmUserClientInfo_HasCamera				=   0x04, //有摄像头
	enmUserClientInfo_HideEnter				=   0x08, //隐身进入
};
typedef uint32_t 				IdentityType;    //对应客户端的 ENM_BusinessType
enum
{
	enmIdentityType_None		=	0x00000000,	//什么也不是的家伙
	enmIdentityType_SONGER		=	0x00000001,	//人气歌手
	enmIdentityType_DANCER		=	0x00000002,	//热舞宝贝
	enmIdentityType_HOST		=	0x00000004,	//闪亮主播
	enmIdentityType_OPERATOR	=	0x00000008,	//线上运营
	enmIdentityType_AGENT		=	0x00000010,	//官方代理
	enmIdentityType_PATROLMAN	=	0x00000020,	//巡管
	enmIdentityType_AD_CLEANER	=	0x00000040,	//广告处理
	enmIdentityType_LUCKY_STAR	=	0x00000080,	//超级幸运星
};

#define ENCODE_DECODE_FILED     -1

typedef int32_t 				AssetUpdateMode;
enum
{
	enmAssetUpdateMode_None      = 0x00000000, //非法的资产更新方式
	enmAssetUpdateMode_Plus      = 0x00000001, //增加
	enmAssetUpdateMode_Minus     = 0x00000002, //减少
};

//充值渠道，共7种渠道：51币， 网银，财付通，支付宝，神州行，天下通，骏网一卡通'

//充值渠道
typedef int32_t 				RechargeChannel;
enum
{
	enmRechargeChannel_None         = 0x00000000,    //无效的资产更新方式
	enmRechargeChannel_51Coin       = 0x00000001,    //51币充值
	enmRechargeChannel_OnlineBank   = 0x00000002,    //网银充值
	enmRechargeChannel_Caifutong    = 0x00000003,    //财付通
	enmRechargeChannel_Zhifubao     = 0x00000004,    //支付宝
	enmRechargeChannel_Shenzhouxing = 0x00000005,    //神州行
	enmRechargeChannel_Tianxiatong  = 0x00000006,    //天下通
	enmRechargeChannel_Junwang      = 0x00000007,    //骏网一卡通
};

typedef uint8_t 				RankListType;
enum
{
	enmRankType_InvalidType				= 0x00,		//无效的排行榜类型
	enmRankType_PopStarRankList			= 0x01,		//明星排行榜
	enmRankType_WealthRankList			= 0x02,		//财富排行榜
	enmRankType_RoomRankList			= 0x03,		//房间排行榜
	enmRankType_GiftRankList			= 0x04,		//礼物之星排行榜
	enmRankType_StampRankList			= 0x05,		//印章之星排行榜
};


/*
* vip等级状态定义：保持不变，增加，减少
*/
typedef int32_t 				VipLevelStatus;
enum
{
	enmVipLevelStatus_Nochange  = 0,   //vip等级未发生改变
	enmVipLevelStatus_Plus      = 1,   //vip等级增加
	enmVipLevelStatus_Minus     = 2,   //vip等级减少
};


typedef uint8_t 				ENM_SystemMessageType;
enum
{
	enumSYSTEMMESSAGETYPE_SYSTEM	= 0x00,//系统消息
	enumSYSTEMMESSAGETYPE_TEXT		= 0x01,//纯文本
	enumSYSTEMMESSAGETYPE_BAOJI		= 0x20,//保级提醒(不包含“尊敬的***”部分)
	enumSYSTEMMESSAGETYPE_INVALID	= 0xff,//不识别的消息
};

typedef uint8_t  				SysChannelType;
enum
{
	enumSysChannelType_Upgrade		= 0x00,//升级频道
	enumSysChannelType_Degrade		= 0x01,//降级频道
	enumSysChannelType_Ranklist		= 0x02,//排行榜频道
	enumSysChannelType_Room			= 0x03,//房间变更频道
	enumSysChannelType_Charge		= 0x04,//更新资产频道
	enumSysChannelType_Invalid		= 0x0ff,//无效的频道
};

typedef uint8_t  				TitleID;
enum
{
	enumTitleID_Notify				= 0x01,//提示
	enumTitleID_SysInfo				= 0x02,//系统消息
	enumTitleID_ChargeCenter		= 0x03,//179充值中心
	enumTitleID_Tips				= 0x04,//温馨提示
	enumTitleID_Invalid				= 0xff,//无效的title
};

/*
* 消息读取类型定义
*/
typedef uint8_t 				MsgReadedType;
enum
{
	enmMsgReadedType_New     = 0x00,      //没有读取
	enmMsgReadedType_Readed  = 0x01,      //已经读取
	enmMsgReadedType_Total   = 0x02,      //所有的，包括已经读取和未读取的
	enmMsgReadedType_Invalid = 0xFF,      //不合法的读取类型
};

//设置自身信息类型
typedef int8_t 					UserInfoType;
enum
{
	enmUserInfoType_Invalid = 0x81,//无效值
	enmUserInfoType_Name = 0x00,
	enmUserInfoType_179ID = 0x01,
	enmUserInfoType_Gender = 0x02,
	enmUserInfoType_VIP_Level = 0x03,
	enmUserInfoType_USR_Level = 0x04,
	enmUserInfoType_Online_Time = 0x05,
	enmUserInfoType_Left_Time = 0x06,
	enmUserInfoType_Birthday_Year = 0x07,
	enmUserInfoType_Birthday_Month = 0x08,
	enmUserInfoType_Birthday_Day = 0x09,
	enmUserInfoType_Home_Province = 0x0a,
	enmUserInfoType_Home_City = 0x0b,
	enmUserInfoType_Self_Setting = 0x0c,
	enmUserInfoType_Magnate_Level = 0x0d,

	//以下room相关字段（room notify）
	enmUserInfoType_Room_Titlelevel = 0x20,//uint16, （部分或全部走单独的通知，***任命***为临管）
	enmUserInfoType_Room_JiaZu = 0x21,//string
	enmUserInfoType_Room_ClientInfo = 0x22,//uint16
	enmUserInfoType_Room_Status = 0x23,
//uint16（部分或全部走单独的通知，***取消***公麦？）
};

typedef int8_t					UserStatusType;
enum
{
	enmUserStatusType_OK = 0,
	enmUserStatusType_Locked = 1,
};

/*
*  系统公告类型
*/
typedef int8_t      SysNoticeType;
enum
{
	enmSysNoticeType_None     = 0x00,    //无效的系统公告类型
	enmSysNoticeType_RoomChat = 0x01,    //房间聊天区公告
	enmSysNoticeType_Roll     = 0x02,    //客户端滚动公告
	enmSysNoticeType_PopFrame = 0x03,    //弹出框公告
};

/*
* 179币改变来源
*/
typedef int8_t MoneyModifySource;
enum
{
	enmMoneyModifySource_None,         //无效的资产修改来源
	enmMoneyModifySource_Artist,       //来源于艺人后台
	enmMoneyModifySource_RoomMaster,   //来源于室主后台
	enmMoneyModifySource_Business,     //来源于运营后台
};

/*
* 系统公告是否已读标示
*/
typedef int8_t   SysNoticeFlag;
enum
{
	enmSysNoticeFlag_Unreaded  = 0x00,    //未读
	enmSysNoticeFlag_Readed    = 0x01,    //已读
};

/*
* 房间信息改变公告的类型
*/
enum
{
	enmRoomNotiType_invalid 	= 0x00,    //无效
	enmRoomNotiType_lock		= 0x01,    //封停
	enmRoomNotiType_Capacity	= 0x02,    //容量改变
	enmRoomNotiType_RankChange	= 0x03,    //用户权限改变
};

/*
* 房间用户权限改变类型
*/
typedef int8_t	RankChangeType;
enum
{
	enmRoomRankChangeType_invalid 	= 0x00,    //无效
	enmRoomRankChangeType_up		= 0x01,    //升级
	enmRoomRankChangeType_down		= 0x02,    //降级
};

typedef uint8_t					UpdateDataType;
enum
{
	enmUpdateDataType_Room		= 0x00,			//更新房间数据
	enmUpdateDataType_Player	= 0x01,			//更新玩家数据
	enmUpdateDataType_CreateRoom= 0x02,			//创建房间
};

typedef uint32_t					PlayerSelfSetting;
enum
{
	enmSelfSeting_P2PShow_Mask		= 0x0180,//1对视频设置mask
	enmSelfSeting_P2PShow_Vip		= 0x0180,//1对视频设置->vip以上
	enmSelfSeting_P2PShow_King		= 0x0100,//1对视频设置->皇冠
	enmSelfSeting_P2PShow_Close		= 0x0080,//1对视频设置->拒绝任何人
};

//状态定义
typedef uint16_t					MicType;
enum
{
	enmMicType_PublicMic		= 0x01,		//公麦
	enmMicType_PublicMicQueue	= 0x02,		//麦序
	enmMicType_PrivateMic		= 0x03,		//私麦
	enmMicType_P2PMic			= 0x04,     //一对一麦上
};

//玩家相关的总时长类型定义
typedef uint8_t UserTotalTimeType;
enum
{
	enmUserTotalTimeType_Invalid   = 0x00,   //无效的玩家总时长类型
	enmUserTotalTimeType_OnLine    = 0x01,   //总的在线时长（只能由大厅发给dbproxy）
	enmUserTotalTimeType_InRoom    = 0x02,   //总的在房间的时长（由roomserver发给dbproxy）
	enmUserTotalTimeType_OnMike    = 0x03,   //总的在麦时长（由roomserver发给dbproxy）
};

//玩家密保状态枚举定义
typedef int8_t  PwdProStatus;
enum
{
	enmPwdProStatus_Unset    = 0x00,     //尚未设置密保
	enmPwdProStatus_Set      = 0x01,     //已经设置密保
};

typedef uint8_t	UpdatePacksackType;
enum
{
	enmUpdatePacksackType_Init	= 0x00,		//第一次初始化我的物品
	enmUpdatePacksackType_Add	= 0x01,		//添加物品
	enmUpdatePacksackType_Del	= 0x02,		//删除物品
};

typedef uint8_t	EditBlackListType;
enum
{
	enmEditBlackListType_Invalid	= 0x00,  //无效
	enmEditBlackListType_Remove		= 0x01,  //删除
	enmEditBlackListType_Add		= 0x02,  //添加
};

/*
* 运营后台封锁类型
*/
typedef int8_t LockType;
enum
{
	enmLockType_Invalid   = 0x00,    //无效
	enmLockType_Player    = 0x01,       //封锁玩家
	enmLockType_IP        = 0x02,       //封锁IP
	enmLockType_Mac       = 0x03,       //封锁Mac地址
};

typedef uint8_t	EditPrivateType;
enum
{
	enmEditPrivateType_Invalid		= 0x00,  //无效
	enmEditPrivateType_Open			= 0x01,  //打开
	enmEditPrivateType_Close		= 0x02,  //关闭
};

typedef int32_t RoomAuditType;
enum
{
	enmRoomAuditType_Unused     = 0,       //未启用
	enmRoomAuditType_Pass       = 1,       //审核通过
	enmRoomAuditType_UnAudited  = 2,       //未审核
	enmRoomAuditType_Refused    = 3,       //官方拒绝修改， 也就是审核没有通过
};

typedef int32_t MicOperateType;
enum
{
	enmMicOperateType_Public_Up       	= 1,       //公麦上
	enmMicOperateType_Private_Up  	  	= 2,       //私麦上
	enmMicOperateType_Public_Dowm       = 3,       //公麦下
	enmMicOperateType_Private_Down  	= 4,       //私麦下
};

/*
* 奖池开关定义
*/
typedef int8_t JackpotFlag;
enum
{
	enmJackpotFlag_Close  = 0,      //奖池开关处于关闭状态（该倍数的奖池无效）
	enmJackpotFlag_Open   = 1,      //奖池开关处于打开状态（该倍数的奖池有效）
};

typedef int8_t EnterRoomType;
enum
{
	enmEnterRoomType_Normal  = 0,      //正常进房
	enmEnterRoomType_Hid   = 1,      //隐身进房
};

//飞屏效果定义
typedef uint8_t	FlyEffectType;
enum
{
	enmFlyEffect_Close	= 0,	//飞屏效果关闭
	enmFlyEffect_Open	= 1,	//飞屏效果打开
};

/*
 * 任务系统相关定义
 */
typedef uint8_t				TaskStatType;
enum
{
	enmTaskType_UnOpen	    = 0x00,          //未打开状态
	enmTaskType_Unfinish	= 0x01,          //未完成状态
	enmTaskType_UnReward    = 0x02,          //不可领取状态
	enmTaskType_Reward	    = 0x03,          //可领取奖励状态
	enmTaskType_IsReward	= 0x04,          //已领取奖励状态
	enmErrorType            = 0xff,          //错误类型
};

typedef uint8_t             OpType;
enum
{
	enmInvalidOpType     = 0x00,             //无效操作类型
	enmCountOpType       = 0x01,             //统计操作类型
	enmOnlyOpType        = 0x02,             //单次操作类型
};

typedef int32_t             TaskID;

typedef uint8_t             EmailStat;       //邮箱状态
enum
{
	enmNotCheckType      =0x00,                //未验证邮箱
	enmCheckedType       =0x01,                //已经验证邮箱
};
//最大可加载的任务数
#define MAX_TASK_COUNT     100

//一个玩家同时可上报的最大行为数
#define MAX_ACTION_COUNT   10
typedef int32_t            ActionID  ;         //行为ID
enum
{
	enmSendItemType      = 0x0001,             //赠送礼物
	enmSendColourBarType = 0x0002,             //发送彩条
	enmCheckEmail        = 0x0003,             //验证邮箱
	enmEditName   		 = 0x0004,             //修改昵称
	enmCollectRoom       = 0x0005,             //收藏房间
	enmRecharge          = 0x0006,             //充值
	enmOnline            = 0x0007,             //在线
};

typedef uint8_t        NickNameStat;            //昵称状态
enum
{
	enmNickName_NotAlterType        =0x00,      //未修改
	enmNickName_AlreadyAlterType    =0x01,      //已经修改
	enmNickName_NoneType            =0xff,      //无效状态
};

typedef uint8_t        RechargeStat;            //昵称状态
enum
{
	enmRecharge_NotAlterType        =0x00,      //未充值
	enmRecharge_OK                  =0x01,      //以前充值过
	enmRecharge_NoneType            =0xff,      //无效状态
};

//富豪等级
typedef uint8_t	MagnateLevel;
enum
{
	enmMagnateLevel_0	= 0,	//无等级
	enmMagnateLevel_1	= 1,	//1富
	enmMagnateLevel_2	= 2,	//2富
	enmMagnateLevel_3	= 3,    //3富
	enmMagnateLevel_4	= 4,    //4富
	enmMagnateLevel_5	= 5,    //5富
	enmMagnateLevel_6	= 6,    //6富
	enmMagnateLevel_7	= 7,    //7富
	enmMagnateLevel_8	= 8,    //8富
	enmMagnateLevel_9	= 9,    //9富
	enmMagnateLevel_10	= 10,   //10富
	enmMagnateLevel_11	= 11,   //知府
	enmMagnateLevel_12	= 12,   //巡抚
	enmMagnateLevel_13	= 13,   //总督
	enmMagnateLevel_14	= 14,   //提督
	enmMagnateLevel_15	= 15,   //少傅
	enmMagnateLevel_16	= 16,   //太傅
	enmMagnateLevel_17	= 17,   //贝勒
	enmMagnateLevel_18	= 18,   //丞相
	enmMagnateLevel_19	= 19,   //藩王
	enmMagnateLevel_20	= 20,   //国公
	enmMagnateLevel_21	= 21,   //郡王
	enmMagnateLevel_22	= 22,   //亲王
	enmMagnateLevel_23	= 23,   //皇子
	enmMagnateLevel_24	= 24,   //太子
	enmMagnateLevel_25	= 25,   //皇帝
};


//沙发操作类型
enum
{
	enmOperateSofa_Invalid	= 0,	//无效
	enmOperateSofa_Update	= 1,	//更新单房间单个位置沙发
	enmOperateSofa_ClearAll	= 2,	//清空所有房间沙发
};

//资产更新操作gameserver定义的错误码
enum
{
	enmErrorCode_UnKnow			= 0xff,	//未知错误
	enmErrorCode_Aguments		= 0x01,	//参数错误
	enmErrorCode_OverMaxMoney	= 0x02,	//资产超过最大限额
	enmErrorCode_NotEnoughMoney	= 0x03,	//币不够
	enmErrorCode_OffLine		= 0x04,	//玩家不在线
};

//订单状态
typedef uint8_t		OrderStatus;
enum
{
	enmOrderStatus_Processing	= 0x00,	//处理中
	enmOrderStatus_Accepted		= 0x01,	//已同意
	enmOrderStatus_Refused		= 0x02,	//已拒绝
	enmOrderStatus_Good			= 0x03,	//已好评
	enmOrderStatus_Bad			= 0x04,	//已差评
	enmOrderStatus_NotVote		= 0x05,	//已弃评
};

//节目状态
typedef uint8_t		ProgramStatus;
enum
{
	enmProgramStatus_WaitingForStart			= 0x00,		//等待节目开始
	enmProgramStatus_FightingForTicket			= 0x01,		//抢票阶段
	enmProgramStatus_Enjoying					= 0x02,		//欣赏节目阶段
	enmProgramStatus_Voteing					= 0x03,		//投票阶段
	enmProgramStatus_ShowResult					= 0x04,		//展示结果阶段
};

typedef uint8_t		SongVoteResult;
enum
{
	enmSongVoteResult_Giveup		= 0x00,		//弃权
	enmSongVoteResult_Good			= 0x01,		//赞
	enmSongVoteResult_Bad			= 0x02,		//差
	enmSongVoteResult_NotVote		= 0x03,		//尚未投票
};

#endif /* PUBLIC_TYPEDEF_H_ */
