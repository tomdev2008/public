/*
 * public_typedef.h
 *
 *  Created on: 2011-12-1
 *      Author: jimm
 */

#ifndef PUBLIC_TYPEDEF_H_
#define PUBLIC_TYPEDEF_H_

#include "common/common_typedef.h"
#include "../lightframe/frame_msg_impl.h"  //IMsgBody�Ķ���

typedef uint8_t						RegionType;
enum
{
	enmInvalidRegionType	= 0x00,
};

typedef uint16_t					RegionID;
enum
{
	enmInvalidRegionID		= 0x0000,      //��Ч�ķ�����
	enmRegionID_179ktv      = 0x0001,      //179ktv����
	enmRegionID_ChatBar     = 0x0002,      //�İ�
	enmRegionID_Show        = 0x0003,      //�㳡
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
*  ��������
*/
typedef uint8_t						RoomType;
enum
{
	enmInvalidRoomType		= 0x00,   /*��Ч��*/
	enmRoomType_Sing        = 0x01,   /*���跿��*/
	enmRoomType_Dance       = 0x02,   /*���跿��*/
	enmRoomType_Chat        = 0x03,   /*�İɷ���*/
	enmRoomType_NewPlayer   = 0x04,   /*���ַ���*/
};

/*
* ����������
*/
typedef uint8_t                    RoomGetType;
enum
{
	enmRoomGetType_None          = 0x00,   /*��Ч�ķ���������*/
	enmRoomGetType_Apply         = 0x01,   /*������*/
	enmRoomGetType_Buy           = 0x02,   /*������*/
};

/*
* ��Ϣ���ͣ����� ��Ӧ��֪ͨ
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
	enmAccountType_Visitor	= 	0x00,   //�ο�
	enmAccountType_179		=	0x01,   //179ע���û�
//	enmAccountType_51		=	0x02,   //51�û�
	enmAccountType_QQ       =   0x02,   //��Ѷ�û�
	enmInvalidAccountType   =   0xff,   //��Ч�˻�����
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
	enmUseMeans_Count		= 0x01,		//����
	enmUseMeans_Time		= 0x02,		//��ʱ
};

struct GoodInfo
{
	ItemID			nItemID;
	int32_t			nCount;				//����
	int32_t			nOwnTick;			//ӵ��ʱ��
	int32_t			nKeepTime;			//����ʱ��
};

struct ItemUnit
{
	ItemID			nItemID;
	UseMeans		nUseMeans;			//ʹ�÷�ʽ
	int32_t			nQuantity;			//�������京��ȡ����ʹ�÷�ʽ��
	int32_t			nOwnTick;			//��Ʒӵ��ʱ��
};

typedef uint8_t						ItemTarget;
enum
{
	enmInvalidItemTarget				= 0x00,
	enmItemTarget_EveryoneExceptSelf	= 0x01,		//���Լ���������κ���
	enmItemTarget_Everyone				= 0x02,		//�κ��ˣ������Լ�
	enmItemTarget_Self					= 0x03,		//�������Լ�����
	enmItemTarget_Nobody				= 0x04,		//������ʹ��
};

typedef uint8_t						ItemRange;
enum
{
	enmInvalidItemRange					= 0x00,
	enmItemRange_One					= 0x01,		//ֻ��һ����
	enmItemRange_AllInRoom				= 0x02,		//�Է���������Ч�û�
	enmItemRange_ManagementInRoom		= 0x03,		//�Է�������(��ʽ����Ա��������������)
	enmItemRange_NormalInRoom			= 0x04,		//�Է���������ͨ�û�
	enmItemRange_AllInRegion			= 0x05,		//���з����ڵ����
	enmItemRange_All					= 0x06,		//�������
};

typedef uint8_t						CompareOperator;
enum
{
	enmInvalidCompareOperator			= 0x00,
	enmCompareOperator_Eq				= 0x01,		//����
	enmCompareOperator_Gt				= 0x02,		//����
	enmCompareOperator_Lt				= 0x03,		//С��
	enmCompareOperator_GE				= 0x04,		//���ڵ���
	enmCompareOperator_LE				= 0x05,		//С�ڵ���
	enmCompareOperator_Ue				= 0x06,		//������
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
	enmKickReason_Relogin = 0x00, //�ظ���½
	enmKickReason_SendAd = 0x01, //���͹��
	enmKickReason_PlayerLock = 0x10,	//��ұ���
	enmKickReason_IPLock = 0x11,	//IP����
	enmKickReason_MacLock = 0x12,	//Mac����
	enmKickReason_Other = 0xff,
};


typedef uint32_t ChangeResult;
enum
{
	enmChangeResult_OK = 0x00,
	enmChangeResult_NO_PERMISSION = 0x01, //û��Ȩ��
	enmChangeResult_Is_Full = 0x02, //�����õĹ�������
	enmChangeResult_Is_AdminInOther = 0x03, //�������ķ����й���Ȩ��
	enmChangeResult_UNKNOWN = 0xff,

};

//״̬����
typedef uint16_t					PlayerState;
enum
{
	enmInvalidPlayerState				= 0x00,		//��Чֵ
	enmPlayerState_InHall				= 0x01,		//�ڴ���
	enmPlayerState_InRoom				= 0x02,		//�ڷ���
	enmPlayerState_PublicMic			= 0x03,		//����
	enmPlayerState_PublicMicQueue		= 0x04,		//������
	enmPlayerState_PrivateMic			= 0x05,		//˽��
	enmPlayerState_PrivateMicQueue		= 0x06,		//˽����
	enmPlayerState_P2PMic				= 0x07,     //һ��һ����
	enmPlayerState_P2PMicAndMicQueue	= 0x08,     //һ��һ��������
};

typedef uint16_t					StatusType;
enum
{
	enmInvalidStatusType           = 0x00,		//��Чֵ
	enmStatusType_PUBLIC_1		 	= 0x01, //1�Ź���
	enmStatusType_PUBLIC_2 			= 0x02, //2�Ź���
	enmStatusType_PUBLIC_3 			= 0x04, //3�Ź���
	enmStatusType_PRIVATE 			= 0x08, //˽��
	enmStatusType_P2P 				= 0x10, //һ��һ��Ƶ
	enmStatusType_FORBIDDEN 		= 0x20, //������
	enmStatusType_VIDEO 			= 0x40, //��Ƶ��
	enmStatusType_AUDIO 			= 0x80,
//��Ƶ��
};


//�ڷ���Ĺ���Ȩ��
typedef uint16_t					RoleRank;
enum
{
	enmRoleRank_None				= 0x00,		//��Ȩ��
	enmRoleRank_TempAdmin			= 0x01,		//��ʱ����Ա
	enmRoleRank_Admin				= 0x02,		//����Ա
	enmRoleRank_MinorHost			= 0x04,		//������
	enmRoleRank_Host				= 0x08,		//����
	enmRoleRank_Super				= 0x10,		//��������Ա����Ӫ��

};

//�㲥��Ϣ������
typedef uint8_t						BroadcastType;
enum
{
	enmBroadcastType_All			= 0x00,		//�����ڵ�������
	enmBroadcastType_ExceptPlayr	= 0x01,		//��ĳ�����֮����������
	enmBroadcastType_ExpectPlayr	= 0x02,		//����֪ͨ��ָ�����
	enmBroadcastType_ExceptRoom		= 0x03,		//��ĳ���������������
};

//������������ر����
typedef uint8_t						FreeShowOpenedType;
enum
{
	enmFreeShowOpenedType_Close			= 0x00,		//��
	enmFreeShowOpenedType_Open	        = 0x01,		//�ر�
};

//������������ر����
typedef uint8_t						PrivateMicOpenedType;
enum
{
	enmPrivateMicOpenedType_Close			= 0x00,		//��
	enmPrivateMicOpenedType_Open	        = 0x01,		//�ر�
};


////��������
//typedef uint8_t							NetType;
//enum
//{
//	enmNetType_Tel						= 0x00,			//����
//	enmNetType_Cnc						= 0x01,			//��ͨ
//	enmNetType_Count					= 0x02,
//};

//av״̬����
typedef uint8_t						AVType;
enum
{
	enmAVType_Open						= 0x00,			//��
	enmAVType_Close						= 0x01,			//�ر�
};

typedef uint32_t					AssetType;
enum
{
	enmInvalidAssetType					= 0x00,
	enmAssetType_Money					= 0x00000001,	//������ҵ�Ǯ
	enmAssetType_Count					= 0x00000002,	//�ʲ����͵�����
	enmAssetType_GoldCoin               = 0x00000003,   //��
	enmAssetType_SpendMoneySum			= 0x00000004,	//����ܻ���
};

typedef uint8_t						UpdateAssetOperate;
enum
{
	enmInvalidUpdateAssetOperate		= 0x00,
	enmUpdateAssetOperate_Increase		= 0x01,			//���
	enmUpdateAssetOperate_Reduce		= 0x02,			//����
};

typedef uint32_t					CauseID;
enum
{
	enmInvalidCauseID					= 0x00,
	enmCauseID_SpendItem				= 0x00000001,	//������߿۷�
	enmCauseID_ItemProfit				= 0x00000002,	//�����ڵ��ߵ����
	enmCauseID_UseItem					= 0x00000003,	//ʹ�õ���(�����)
	enmCauseID_ItemTimeout				= 0x00000004,	//���߳�ʱ
	enmCauseID_LuckyProfit				= 0x00000005,	//�����н�
	enmCauseID_GodWealthProfit			= 0x00000006,	//�������Ľ���
	enmCauseID_GodWealthAndItemProfit	= 0x00000007,	//������Ľ����͵�������
	enmCauseID_GoodExpire				= 0x00000008,	//��Ʒ����
	enmCauseID_FromGameServer			= 0x00000009,	//����gameserver�ļӼ�������
	enmCauseID_RequestSong				= 0x0000000a,	//������
	enmCauseID_AcceptRequestSong		= 0x0000000b,	//���ܵ��
	enmCauseID_RefuseRequestSong		= 0x0000000c,	//�ܾ����
};

typedef int32_t						UpdateUserAsset;
enum
{
	enmUpdateUserAsset_OK				= 0x00000000,
	enmUpdateUserAsset_NotEnoughMoney	= 0x00000001,	//Ǯ����
	enmUpdateUserAsset_DestNotFound		= 0x00000002,	//Ŀ�����û���ҵ�
	enmUpdateUserAsset_Timeout			= 0x00000003,	//��ʱ
	enmUpdateUserAsset_Unknown			= 0x00000004,	//δ֪����
};

typedef uint8_t						ItemType;
enum
{
	enmInvalidItemType					= 0x00,
	enmItemType_Normal					= 0x01,			//��ͨ
	enmItemType_Luxury					= 0x02,			//�ݳ�
	enmItemType_Lucky					= 0x03,			//����
	enmItemType_Stamp					= 0x04,			//ӡ��
	enmItemType_GodOfWealth				= 0x05,			//����
	enmItemType_Firework				= 0x06,			//�̻�
	enmItemType_SaultingGun				= 0x07,			//����
	enmItemType_LoudSpeaker				= 0x08,			//����
	enmItemType_ChooseSong				= 0x09,			//�������
	enmItemType_BlinkEnter				= 0x0a,			//�����ǳ�
	enmItemType_ChangeVoice				= 0x0b,			//������
	enmItemType_FlyWords				= 0x0c,			//����
	enmItemType_Sofa					= 0x0d,			//ɳ��
	enmItemType_RequestSong				= 0x0e,			//���
};

typedef uint8_t						UpdateItemOperate;
enum
{
	enmInvalidUpdateItemOperate			= 0x00,
	enmUpdateItemOperate_Add			= 0x01,			//����
	enmUpdateItemOperate_Update			= 0x02,			//����
	enmUpdateItemOperate_Del			= 0x03,			//ɾ��
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
	enmSpeakerMessageType_Loud			= 0x00,			//������Ϣ
	enmSpeakerMessageType_Lucky			= 0x01,			//������Ʒ��500��1000����Ϣ
	enmSpeakerMessageType_System		= 0x02,			//ϵͳ������Ϣ
	enmSpeakerMessageType_GodWealth		= 0x03,			//�콵������Ϣ
	enmSpeakerMessageType_GameReward    = 0x04,         //��Ϸ�н���Ϣ
	enmSpeakerMessageType_Luxury		= 0x05,			//�ݳ�Ʒ��Ϣ
};

//class ConnUin
//{
//public:
//	uint8_t					nVersion;				//�汾
//	uint8_t					nServerID;				//tunnel server��id
//	uint16_t				nTunnelIndex;			//tunnel server���ڲ�����
//	int32_t					nRoleID;				//�û�id
//	int32_t					nCreateTime;			//���Ӵ���ʱ��
//	uint32_t				nIsn;					//���к�,��tunnel server����
//	uint32_t				nAddress;				//ip
//	uint16_t				nPort;					//�˿�
//	NetType					nNetType;				//��ʾ�ͻ��˵���������
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

//���/��Сֵ����
#if defined(DEBUG) || defined(_DEBUG) || defined(_DEBUG_)
#define MaxTokenBuffSize				2048
//����˺ų���
#define	MaxAccountName					32
//����������󳤶�
#define MaxRoomNameLength				64
//Ƶ��������󳤶�
#define MaxChannelNameLength			128
//����������󳤶�
#define MaxRegionNameLength				64
//һ��������������û�����
#define MaxUserCountPerRoom				1300
//������û�Ͱ��С
#define RoomPlayerBucketSize			((MaxUserCountPerRoom) * 4)
//һ������������ɹ���Ա����
#define MaxAdminCountPerRoom			520
//����Ĺ���ԱͰ��С
#define RoomAdminBucketSize				((MaxAdminCountPerRoom) * 4)
//һ��Ƶ�����ķ�������
#define MaxRoomCountPerChannel			200
//Ƶ���ķ���Ͱ��С
#define ChannelBucketSize				((MaxRoomCountPerChannel) * 4)
//һ����������Ƶ������
#define MaxChannelCountPerRegion		32
//һ������������Ƶ��������
#define MaxChannelCountPerServer		32
//һ��������������Ҷ�����
#define MaxPlayerCountPerServer			10000
//һ�����������ķ�����
#define MaxRoomCountPerServer			500
//Ĭ��չʾ�ķ����û�����ֵ
#define MaxDefaultShowUserLimit			300
//��ʵ�ķ����û�����ֵ
#define MaxDefaultRealUserLimit			500
//���ķ�����
#define MaxRegionCount					32
//����ͬʱ����ķ�����
#define MaxEnterRoomCount				12
//�����ַ�������
#define MaxStringLength					65535
//�û��ǳƵ���󳤶�
#define MaxRoleNameLength				64
//�û�����ԭ�����󳤶�
#define MaxKickedReasonLength			128
//���ķ�����
#define MaxRoomCount					50
//����mediaserver��
#define MaxMediaCount					50
//����Ͱ��С
#define RoomBucketSize					((MaxRoomCount) * 4)
//����server����ÿһ�ַ�������
#define MaxServerCount					32
//�����������
#define MaxOnlinePlayerCount			1000
//����ת������
#define MaxTransmitUserCount			MaxUserCountPerRoom
//���ķ������볤��
#define MaxRoomPasswordLength			32
//�������������
#define MaxRoomBlackListSize			1000
//���������������
#define MaxRoomProhibitSpeakSize		2
//����IP�������
#define MaxRoomLockIP					1000
//һ��������������Ϣͷ����
#define MaxMsgHeadCountPerServer        10000
//�߳������������
#define MaxRoomKickListSize				1000
//��󷿼�ǩ������
#define MaxRoomSignatureSize			512
//����Ƕ��ٸ�����Ĺ���Ա
#define MaxBeAdminPerPlayer				32
//�����ı�����
#define MaxTextMessageSize				1024
//fonttype���ַ�������
#define MaxFontTypeStringSize			512
//���乫���������
#define MaxPublicMicCount				3
//������������
#define MaxWaittingMicCount				50
//����˽������
#define MaxPrivateMicCount				MaxAdminCountPerRoom
//ÿ������������
#define MaxPerKickCount				    200
//ÿ��mediaserver�����ķ�����
#define MaxRoomCountPerMedia			1000
//����������󳤶�
#define MaxItemNameSize					64
//һ�ο������õķ�����Ϣ����
#define MaxSetRoomTypeCount				4
//һ�ο��Ի�ȡ�ķ�����Ϣ����
#define MaxGetRoomTypeCount				12
//���������ַ�����󳤶�
#define MaxSetRoomTextSize				1024
//���乫�����ֵ
#define MaxRoomNoticeLength				1024
//�����������ֵ
#define MaxRoomSignatureLength			512
//���件ӭ�����ֵ
#define MaxRoomWelcomeLength			1024
//���������н�����
#define MaxLuckyCount					100
//�������������ʹ�õ�Item������
#define MaxOnUserItemCount				32
//���������������Ʒ����
#define MaxPlayerGoodsCount				32
//һ�����ɸ��µ��ʲ�����
#define MaxUpdateAssetCount				32
//һ�����ɸ��¶����û����ʲ�
#define MaxBatchUpdateRoleAssetCount	1000
//���ĵ�������
#define MaxItemKindCount				0xffff
//�����˷��Ͳ����Ķ�ʱ����ʱʱ�䣨�룩
#define RobotSendColorTimeOut			1
//������������
#define MaxDefallCount					10
//������Ʒ�����е���󽱳���
#define MaxJackpotCountPerLuckyItem		8
//����������ַ�������󳤶�
#define MaxLockPlayerReasonLength		128
//����������ַ�������󳤶�
#define MaxKickPlayerReasonLength		128
//��¼ʧ�������ַ�������󳤶�
#define MaxLoginFailReasonLength		128
//һ�����ܻ�ȡ����󽱳���Ϣ����
#define MaxGetJackpotInfoCount			10
//�������������ַ�������󳤶�
#define MaxLockRoomReasonLength         128
//��ͨ������ʾ��Ϣ��󳤶�
#define MaxLaunchRoomNoticeLength       128
//���������ݴ�С
#define MaxUpdateDataSize				1024 * 8
//һ������ؽ�������ݵĸ���
#define MaxBuildPlayerDataCount			10
//һ������ؽ��������ݵĸ���
#define MaxBuildRoomDataCount			10
//һ������������ռ���ڴ��С
#define RoomCacheSize					1024 * 200
//һ����������������ռ���ڴ��С
#define HallRoomCacheSize				200
//һ�����������ռ���ڴ��С
#define PlayerCacheSize					1024 * 20
//roomdispatcher��������roomserver����
#define MaxRoomServerCountPerRoomDispatcher	12
//һ���ͬʱ��õ�����֮�ǵĸ���
#define MaxGiftStarCount				32
//һ�οɻ�ȡ��������Ҵ�С
#define MaxGetOnlinePlayerCount			100
//�������ݴ�С
#define MaxFlyWordsMessageSize			512
//mac�ַ�������
#define MaxMacAddrStringLength			32
//��IPԭ�����󳤶�
#define MaxLockIPReasonLength           MaxLockPlayerReasonLength
//ÿ�η�ͣ��������
#define MaxLockCountOnce   100
//���ķ�ͣ���ݵĳ���
#define MaxLockContentLength            128
//�����ʲ�ʧ��ԭ�����󳤶�
#define MaxAssetUpdateFailReasonLength  512
//���Ŀͻ�������ʧ��ԭ��
#define MaxReqFailReasonLength  		128
//���Ĺۿ�˽�������
#define MaxWatchPrivateMicCount			10
//һ���������ͷ����������������
#define MaxPlayerCountPerRoomServer		150
//�Ӻ�̨������ȡ����������������������
#define MaxGetPlayerOnlineStatusNum		50
//�ʲ�����ԭ�����󳤶�
#define MaxAssetUpdateReasonLength      512
//�û����绷��ͳ��keyֵ����󳤶�
#define MaxRoomCollectionKeyLen         128
//�û����绷��ͳ������ֵ����󳤶�
#define MaxRoomCollectionContentLen   512
//�û����绷��ͳ���������ֵ��ÿһ�Ρ�
#define MaxRoomCollectionInfoCount  100
//ÿ���û�����ӵ�е����ĳɾ͵ĸ���
#define MaxAchieveCount  10
//����״��ͳ���������ֶ�������
#define MaxFieldCountInNetStatus       10
//����״��ͳ����ÿ���ֶε���󳤶�
#define MaxFieldLenInNetStatus         50
//��ǰ����״��ͳ���������ֶεĸ���: netname + media + ip + lost_ratio
#define CurFieldCountInNetStatus       4
//�������͵���󳤶�
#define MaxNetTypeLen  64
//����Ƶ����
#define MaxChannelID  1000000000
//ÿ�����а��������
#define MaxFansCountPerType   5
//ÿ����Ϣ�����Է��͸����ٸ�server
#define MAX_DST_SERVER_COUNT 32
//ÿ��server����Ϣ�����ļ�������ж�����
#define MaxMsgCount 128
//�ֶζ�Ӧ���ַ�������󳤶�
#define MaxFieldStringLen 1024
//�ͻ�����Ϸ���Ƶ����̶�
#define MaxGameNameLength  256
//��ȡ�û��һ���¼�����������ÿ������ܻ�ȡ��������
#define MaxExchangeLogCountPerTime 128
//��������󳤶�
#define MaxSongNameLength				256
//ÿλ���ֵĸ赥���ĸ�����
#define MaxSongCountPerPlayer			50
//���˸����б����������
#define MaxSongListMgtSize				2000
//�����������Ƹ�����
#define MaxHotSongCountPerPlayer		5
//ף�������ĳ���
#define MaxWishWordsLength				512
//���ͶƱƱ��
#define MaxVoteTicketsCount				32
//�û�ͷ��������󳤶�
#define MaxThumbLength                  255
//�������������
#define MAX_ARTIST_NUM                  200
//����ղط�������
#define MaxCollectCount					50
//��󻺴���˺ų�����
#define MaxCacheUnusedAccountCount		1000
#else
#define MaxTokenBuffSize				2048
//����˺ų���
#define	MaxAccountName					32
//����������󳤶�
#define MaxRoomNameLength				64
//Ƶ��������󳤶�
#define MaxChannelNameLength			128
//����������󳤶�
#define MaxRegionNameLength				64
//һ��������������û�����
#define MaxUserCountPerRoom				1300
//������û�Ͱ��С
#define RoomPlayerBucketSize			((MaxUserCountPerRoom) * 4)
//һ������������ɹ���Ա����
#define MaxAdminCountPerRoom			520
//����Ĺ���ԱͰ��С
#define RoomAdminBucketSize				((MaxAdminCountPerRoom) * 4)
//һ��Ƶ�����ķ�������
#define MaxRoomCountPerChannel			1024
//Ƶ���ķ���Ͱ��С
#define ChannelBucketSize				((MaxRoomCountPerChannel) * 4)
//һ����������Ƶ������
#define MaxChannelCountPerRegion		128
//һ������������Ƶ��������
#define MaxChannelCountPerServer		128
//һ��������������Ҷ�����
#define MaxPlayerCountPerServer			10000
//һ�����������ķ�����
#define MaxRoomCountPerServer			1024
//Ĭ��չʾ�ķ����û�����ֵ
#define MaxDefaultShowUserLimit			300
//��ʵ�ķ����û�����ֵ
#define MaxDefaultRealUserLimit			500
//���ķ�����
#define MaxRegionCount					32
//����ͬʱ����ķ�����
#define MaxEnterRoomCount				12
//�����ַ�������
#define MaxStringLength					65535
//�û��ǳƵ���󳤶�
#define MaxRoleNameLength				64
//�û�����ԭ�����󳤶�
#define MaxKickedReasonLength			128
//���ķ�����
#define MaxRoomCount					20000
//����mediaserver��
#define MaxMediaCount					2000
//����Ͱ��С
#define RoomBucketSize					((MaxRoomCount) * 4)
//����server����ÿһ�ַ�������
#define MaxServerCount					32
//�����������
#define MaxOnlinePlayerCount			100000
//����ת������
#define MaxTransmitUserCount			MaxUserCountPerRoom
//���ķ������볤��
#define MaxRoomPasswordLength			32
//�������������
#define MaxRoomBlackListSize			1000
//���������������
#define MaxRoomProhibitSpeakSize		1000
//����IP�������
#define MaxRoomLockIP					1000
//һ��������������Ϣͷ����
#define MaxMsgHeadCountPerServer        10000
//�߳������������
#define MaxRoomKickListSize				1000
//��󷿼�ǩ������
#define MaxRoomSignatureSize			512
//����Ƕ��ٸ�����Ĺ���Ա
#define MaxBeAdminPerPlayer				32
//�����ı�����
#define MaxTextMessageSize				1024
//fonttype���ַ�������
#define MaxFontTypeStringSize			512
//���乫���������
#define MaxPublicMicCount				3
//������������
#define MaxWaittingMicCount				50
//����˽������
#define MaxPrivateMicCount				MaxAdminCountPerRoom
//ÿ������������
#define MaxPerKickCount				    200
//ÿ��mediaserver�����ķ�����
#define MaxRoomCountPerMedia			1000
//����������󳤶�
#define MaxItemNameSize					64
//һ�ο������õķ�����Ϣ����
#define MaxSetRoomTypeCount				4
//һ�ο��Ի�ȡ�ķ�����Ϣ����
#define MaxGetRoomTypeCount				12
//���������ַ�����󳤶�
#define MaxSetRoomTextSize				1024
//���乫�����ֵ
#define MaxRoomNoticeLength				1024
//�����������ֵ
#define MaxRoomSignatureLength			512
//���件ӭ�����ֵ
#define MaxRoomWelcomeLength			1024
//���������н�����
#define MaxLuckyCount					100
//�������������ʹ�õ�Item������
#define MaxOnUserItemCount				32
//���������������Ʒ����
#define MaxPlayerGoodsCount				32
//һ�����ɸ��µ��ʲ�����
#define MaxUpdateAssetCount				32
//һ�����ɸ��¶����û����ʲ�
#define MaxBatchUpdateRoleAssetCount	2000
//���ĵ�������
#define MaxItemKindCount				0xffff
//�����˷��Ͳ����Ķ�ʱ����ʱʱ�䣨�룩
#define RobotSendColorTimeOut			1
//������������
#define MaxDefallCount					10
//������Ʒ�����е���󽱳���
#define MaxJackpotCountPerLuckyItem		8
//����������ַ�������󳤶�
#define MaxLockPlayerReasonLength		128
//����������ַ�������󳤶�
#define MaxKickPlayerReasonLength		128
//��¼ʧ�������ַ�������󳤶�
#define MaxLoginFailReasonLength		128
//һ�����ܻ�ȡ����󽱳���Ϣ����
#define MaxGetJackpotInfoCount			10
//�������������ַ�������󳤶�
#define MaxLockRoomReasonLength         128
//��ͨ������ʾ��Ϣ��󳤶�
#define MaxLaunchRoomNoticeLength       128
//���������ݴ�С
#define MaxUpdateDataSize				1024 * 8
//һ������ؽ�������ݵĸ���
#define MaxBuildPlayerDataCount			10
//һ������ؽ��������ݵĸ���
#define MaxBuildRoomDataCount			10
//һ������������ռ���ڴ��С
#define RoomCacheSize					1024 * 200
//һ����������������ռ���ڴ��С
#define HallRoomCacheSize				200
//һ�����������ռ���ڴ��С
#define PlayerCacheSize					1024 * 20
//roomdispatcher��������roomserver����
#define MaxRoomServerCountPerRoomDispatcher	12
//һ���ͬʱ��õ�����֮�ǵĸ���
#define MaxGiftStarCount				32
//һ�οɻ�ȡ��������Ҵ�С
#define MaxGetOnlinePlayerCount			100
//�������ݴ�С
#define MaxFlyWordsMessageSize			512
//mac�ַ�������
#define MaxMacAddrStringLength			32
//��ipԭ���ַ����Ĵ�С
#define MaxLockIPReasonLength           MaxLockPlayerReasonLength
//ÿ�η�ͣ��������
#define MaxLockCountOnce   100
//���ķ�ͣ���ݵĳ���
#define MaxLockContentLength            32
//�����ʲ�ʧ��ԭ�����󳤶�
#define MaxAssetUpdateFailReasonLength  512
//���Ŀͻ�������ʧ��ԭ��
#define MaxReqFailReasonLength  		128
//���Ĺۿ�˽�������
#define MaxWatchPrivateMicCount			30
//һ���������ͷ����������������
#define MaxPlayerCountPerRoomServer		10000
//�Ӻ�̨������ȡ����������������������
#define MaxGetPlayerOnlineStatusNum		50
//�ʲ�����ԭ�����󳤶�
#define MaxAssetUpdateReasonLength      512
//�û����绷��ͳ��keyֵ����󳤶�
#define MaxRoomCollectionKeyLen         128
//�û����绷��ͳ������ֵ����󳤶�
#define MaxRoomCollectionContentLen   512
//�û����绷��ͳ���������ֵ��ÿһ�Ρ�
#define MaxRoomCollectionInfoCount  100
//ÿ���û�����ӵ�е����ĳɾ͵ĸ���
#define MaxAchieveCount  10
//����״��ͳ���������ֶ�������
#define MaxFieldCountInNetStatus       10
//����״��ͳ����ÿ���ֶε���󳤶�
#define MaxFieldLenInNetStatus         50
//��ǰ����״��ͳ���������ֶεĸ���: netname + media + ip + lost_ratio
#define CurFieldCountInNetStatus       4
//�������͵���󳤶�
#define MaxNetTypeLen  64
//����Ƶ����
#define MaxChannelID  1000000000
//ÿ�����а��������
#define MaxFansCountPerType   5
//ÿ����Ϣ�����Է��͸����ٸ�server
#define MAX_DST_SERVER_COUNT 32
//ÿ��server����Ϣ�����ļ�������ж�����
#define MaxMsgCount 128
//�ֶζ�Ӧ���ַ�������󳤶�
#define MaxFieldStringLen 1024
//�ͻ�����Ϸ���Ƶ����̶�
#define MaxGameNameLength  256
//��ȡ�û��һ���¼�����������ÿ������ܻ�ȡ��������
#define MaxExchangeLogCountPerTime 128
//��������󳤶�
#define MaxSongNameLength	256
//ÿλ���ֵĸ赥���ĸ�����
#define MaxSongCountPerPlayer			50
//���˸����б����������
#define MaxSongListMgtSize				2000
//�����������Ƹ�����
#define MaxHotSongCountPerPlayer		5
//ף�������ĳ���
#define MaxWishWordsLength				512
//���ͶƱƱ��
#define MaxVoteTicketsCount				32
//�û�ͷ��������󳤶�
#define MaxThumbLength                  255
//�������������
#define MAX_ARTIST_NUM                  200
//����ղط�������
#define MaxCollectCount					50
//��󻺴���˺ų�����
#define MaxCacheUnusedAccountCount		100000
#endif

//���ֵö�ٶ���
enum
{
	enmMaxSerialNumberLength		= 40,	//��ˮ����󳤶�
	enmMaxTimeStringLength			= 128,	//���ʱ�������ַ���
};

//��Чֵ����
enum
{
	enmInvalid16BitsIndex		= 0xffff,
	enmInvalid32BitsIndex		= 0xffffffff,
	enmInvalid16BitsValue		= 0xffff,
	enmInvalid32BitsValue		= 0xffffffff,
};


//Ĭ��ֵ����



//vvip�ȼ�
typedef uint8_t					VipLevel;
enum 
{
	enmVipLevel_NONE 				= 0x00, //δע��
	enmVipLevel_Regist	 			= 0x01, //��ע��
	enmVipLevel_Gold 				= 0x02, //�ƽ�vip
	enmVipLevel_Diamond 			= 0x04, //��ʯvip
	enmVipLevel_Baron 				= 0x08, //�о�
	enmVipLevel_Viscount 			= 0x10, //�Ӿ�
	enmVipLevel_Earl 				= 0x20, //����
	enmVipLevel_Marquis 			= 0x40, //���
	enmVipLevel_Duke 				= 0x60, //����
	enmVipLevel_King 				= 0x80, //����
};

//�û��ȼ�
typedef uint8_t					UserLevel;


//����������
enum
{
	enmEntityType_None				= 0x00,				//��Чֵ

	enmEntityType_Example			= 0x01,				//����������
	enmEntityType_Router			= 0x02,				//·����
	enmEntityType_Connect			= 0x03,				//�������ӷ�����
	enmEntityType_Hall				= 0x04,				//����������
	enmEntityType_Media				= 0x05,				//ý�������
	enmEntityType_Tunnel			= 0x06,				//������������
	enmEntityType_Room				= 0x07,				//���������
	enmEntityType_Item				= 0x08,				//���߷�����
	enmEntityType_DBProxy			= 0x09,				//���ݿ����������� ר����д����
	enmEntityType_WebConn           = 0x0A,             //web���ӷ�����
	enmEntityType_Webagent          = 0x0B,             //����������Ĵ��������(��Ҫ����Ϊweb����server֮���Э��ת��)
	enmEntityType_Account			= 0x0C,				//�˺�ע�������
	enmEntityType_SysInfo			= 0x0D,				//ϵͳ��Ϣ������
	enmEntityType_Daemon			= 0x0E,				//�ػ�����
	enmEntityType_RoomDispatcher	= 0x10,				//����ַ�������
	enmEntityType_DBProxyRead       = 0x11,             //ר�����������dbproxy
	enmEntityType_Task              = 0x12,             //���������
	enmEntityType_NewWebConn        = 0x13,             //�°�web���ӷ�����, ʮ����Ϊ19
	enmEntityType_HallDataCenter    = 0x14,             //�������ݱ��ݷ�����
	enmEntityType_ClientGame        = 0x15,             //�ͻ�����Ϸ������
	enmEntityType_Transmiter		= 0x16,				//ý����ת������
	enmEntityType_AccountAgent		= 0x17,				//�ʺŴ��������
	enmEntityType_OptGate			= 0x18,				//��Ӫ��̨���ط�����

	enmEntityType_Count				= 0x18,				//���������͸���
	enmEntityType_Client			= 0x80,				//�ͻ���
	enmEntityType_Web				= 0x81,				//web�ͻ���
};

//ԭ����
typedef uint8_t					LogoutReason;
enum
{
	enmLogoutReason_Unknown			= 0x00,				//δ֪
	enmLogoutReason_ClientRequest	= 0x00,				//�ͻ��������˳�
	enmLogoutReason_ClientDisconnect= 0x01,				//�ͻ��˵���
	enmLogoutReason_Relogin			= 0x02,				//�ظ���½
	enmClientCloseReason_Tunnel_RecvStartRequestWhenUse = 102, //���Ӷ����յ��ĵ�һ������ʱ���Ѿ��Ǳ�ʹ��״̬����TunnelServer�ĵ�
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

//��һ��һ��Ƶ����
typedef uint8_t					ResponseP2PType;
enum
{
	enmRESPONSEP2PTYPE_ACCEPT			=	0x00,  //����
	enmRESPONSEP2PTYPE_REFUSE			=	0x01,  //�ܾ�
};

////��Ʒ��ʹ�÷�ʽ
//typedef uint8_t   UseMeans;
//enum
//{
//	enmUseMeans_None                   = 0x00,   //��Ч��ʹ�÷�ʽ
//	enmUseMeans_Time                   = 0x01,   //��ʱʹ��
//	enmUseMeans_Count                  = 0x02,   //����ʹ��
//	enmUseMeans_Trig                   = 0x03,   //����ʹ��
//};

//�ʲ���������
typedef uint8_t AssetUpdateChannel;
enum
{
	enmAssetUpdateChannel_None              = 0x00,   //��Ч���ʲ���������
	enmAssetUpdateChannel_Recharge          = 0x01,   //��ֵ
	enmAssetUpdateChannel_Add               = 0x02,   //��Ӫ��Աֱ�Ӹ���Ҽ�Ǯ
	enmAssetUpdateChannel_RoomHostGet       = 0x03,    //������ȡ����
	enmAssetUpdateChannel_RoomHost179Plant  = 0x04,  //����179���ֻ�
	enmAssetUpdateChannel_RoomHostSongReq   = 0x05,  //����ʹ�õ��С���ֻ�
	enmAssetUpdateChannel_Artist179Plant    = 0x06,   //������179���ֻ�
	enmAssetUpdateChannel_ArtistSongReq     = 0x07,   //�����õ��С���ֻ�
	enmAssetUpdateChannel_Contribution      = 0x08,   //����Ա��̨��ȡ���ף� ����ͻ������½ǵ���
	enmAssetUpdateChannel_Reward            = 0x09,   //�Ƽ��˻�ó�ֵ����, B�Ƽ�A�� Ȼ��A����ֵ����ʱ��B����һ����179��
	enmAssetUpdateChannel_PayReward         = 0x0A,   //��ֵ�ﵽһ������÷���
	enmAssetUpdateChannel_UpgradeReward     = 0x0B,   //����������͵ı�
	enmAssetUpdateChannel_TaskChargeReward	= 0x0C,		//����ϵͳ�״γ�ֵ��ý���
	enmAssetUpdateChannel_GameReward        = 0x0d,    //��Ϸ����
};

//���ֵ����
enum
{
	enmMaxRoomIDSBufLength 			= 512,         //user_base_info���е�roominfo�ֶε���󳤶�
	enmMaxRoomIDStringLength 		= 16,        //���͵�roomid��Ӧ���ַ�������󳤶�
	enmMaxUserOwnRoomCount   		= 128,       //���ӵ�еķ���������
	enmMaxToRoleCount        		= 800,      //�������ͬʱ�͸�������
	enmMaxRoleBaseInfoBufLen 		= 1024 * 16,    //��һ�����Ϣ����������󳤶�
	enmMaxRoomBaseInfoBufLen 		= 1024,    //��һ�����Ϣ����������󳤶�
	enmMaxBillTransIDLen     		= 128,     //�˵���ˮ�ŵ���󳤶�
	enmMaxProvinceNameLength        = 32,    //���ʡ�����Ƴ���
	enmMaxCityNameLength            = 32,    //�����������
	enmMaxCountyNameLength          = 32,    //�����������
	enmMaxAddrLength                = 32 * 3, //����������
	enmMaxHoroScopeNameLength       = 32,     //����������Ƴ���
	enmMaxEmailAddrLength           = 32,     //��������ַ����
	enmMaxPasswordLength			= 32,	  //������볤��
	enmMaxPassportLength			= 64,	  //����¼�����
	enmMaxPlatformLength			= 64,	  //���ƽ̨���ֳ���
	enmMaxChannelIDLength			= 32,	  //���������ų���
	enmMaxTelephoneLength           = 16,     //�ֻ�������󳤶�
	enmMaxQQLength                  = 16,     //QQ�������󳤶�
	enmMaxAccountSrcLength          = 32,     //�˻���Դ��󳤶�
	MaxRoleIDStringLength           = 16,     //roleid��Ӧ���ַ�������󳤶�
	enmMaxWelcomewordsLength        = 128,    //���件ӭ�ʵ���󳤶�
	enmMaxRegionNameLength          = 32,     //�����������Ƴ���
	enmMaxAccountTypeLength         = 16,     //�˺����Ͷ�Ӧ���ַ�������󳤶�
	enmMaxRoleIDStringLength        = 32,     //roleid��Ӧ���ַ�������󳤶�
	enmMinMessageSize               = 1024,      //Ϊ��dump�Ƚ�С����Ϣ������ֻ�м����������͵��ֶΣ�Ϊ��Լջ�ռ䣩�����ô�ֵ
	enmNormalMessageSize            = 1024 * 8, //������������Ϣ�ĳ��ȣ���Ϊ֮ǰ�õ���enmMaxMessageSize�� ���ֵ��256K��
  											    //�����Ӵ�Ϊ�˽�ʡ�ڴ棬�����²ߣ����ڲ�̫�����Ϣ���������������Ϊ��Ϣ�Ĵ�С��
	enmMaxPlayerMoney               =  4000000000,   //��ҵ�Ǯ�����������40�ڱң� ��Ӧ����� 400��
};

typedef uint8_t RoomInfoType;
enum
{
	enmRoomInfoType_NAME			    =	0x00, //string��������
	enmRoomInfoType_SIGNATURE			=	0x01, //string ��������
	enmRoomInfoType_PASSWORD			=	0x02, //string(�մ���û������)
	enmRoomInfoType_FREESHOW_TIME		=	0x03, //uint8(��������ʱ����ʱ��,min)
	enmRoomInfoType_WELCOME_WORDS		=	0x04, //string(��ӭ��)
	enmRoomInfoType_NOTICE				=	0x05, //string(����)
	enmRoomInfoType_OPTION				=	0x06, //uint32(RoomOptionType)
	enmRoomInfoType_Mic_First_Status	=   0x07,
	enmRoomInfoType_Mic_Second_Status	=   0x08,
	enmRoomInfoType_Mic_Third_Status	=   0x09,
	enmRoomInfoType_Count				=   0x0a,  //���ڵõ����ڷ������÷�Ϊ���󲿷�
};


//��������
typedef uint32_t				RoomOptionType;
enum
{
	enmRoomOptionType_Room_Close				= 0x0000001,        //���䴦�ڹر�״̬
	enmRoomOptionType_Public_Chat_Vip         = 0x0000002,        //vip���Թ���
	enmRoomOptionType_Color_Text_Close          = 0x0000004,        //�����ر�
	enmRoomOptionType_User_InOut_Open           = 0x0000008,        //�û�������Ϣ��
	enmRoomOptionType_FreeShow_Open	       	    = 0x0000010,		//���������ڴ�״̬
	enmRoomOptionType_FreeShow_ForManager_Close	= 0x0000020,		//���ƹ���Ա��ʱ
	enmRoomOptionType_FreeShow_Edit_Time_Close	= 0x0000040,		//����Ա�������޸���ʱ
	enmRoomOptionType_Has_PrivateMic			= 0x0000080,		//��˽��
	enmRoomOptionType_PrivateMIC_Close			= 0x0000100,		//˽���ڹر�״̬
	enmRoomOptionType_Auto_Welcome_Close		= 0x0000200,		//�Զ���ӭ�ر�
	enmRoomOptionType_Show_RoomName_Close		= 0x0000400,		//()
};

//ϵͳ��Ϣ����
#define MaxInfoSize		1024
#define MaxTitleSize	64
#define MaxNotiCount	10
#define UserCountEveryTime 100
#define MaxDegradeCountEveryTime 1000//����������count�� ,1.7�汾��ʱ��
#define MaxRankListTypes 50
#define MaxMsgContentLen 1024
#define MaxGetMsgCount 	50
#define MaxNoticeTitleLen 32
#define MaxNoticeCount 50
#define MaxGetOnlinePlayerLefMoneyCount	500
#define MaxIdentityCount	32
#define MaxItemMsgLength	256
#define MaxPerGetRoomSofaCount		500
#define ROOM_SOFACOUNT	5	//���������ɳ������

//ItemServer����
#define MaxPerGetLuckyUserCount	100 //����ȡ�������н���ҵĸ���

typedef uint8_t  				PlayerType;
enum
{
	enmPlayerType_Normal			    =	0x00, //������
	enmPlayerType_Rebot					=	0x01, //������
};

typedef uint16_t 				UserClientInfo;
enum
{
	enmUserClientInfo_PC			    	=	0x00, //PC�û�
	enmUserClientInfo_Web					=	0x01, //Web�û�
	enmUserClientInfo_HasCamera				=   0x04, //������ͷ
	enmUserClientInfo_HideEnter				=   0x08, //�������
};
typedef uint32_t 				IdentityType;    //��Ӧ�ͻ��˵� ENM_BusinessType
enum
{
	enmIdentityType_None		=	0x00000000,	//ʲôҲ���ǵļһ�
	enmIdentityType_SONGER		=	0x00000001,	//��������
	enmIdentityType_DANCER		=	0x00000002,	//���豦��
	enmIdentityType_HOST		=	0x00000004,	//��������
	enmIdentityType_OPERATOR	=	0x00000008,	//������Ӫ
	enmIdentityType_AGENT		=	0x00000010,	//�ٷ�����
	enmIdentityType_PATROLMAN	=	0x00000020,	//Ѳ��
	enmIdentityType_AD_CLEANER	=	0x00000040,	//��洦��
	enmIdentityType_LUCKY_STAR	=	0x00000080,	//����������
};

#define ENCODE_DECODE_FILED     -1

typedef int32_t 				AssetUpdateMode;
enum
{
	enmAssetUpdateMode_None      = 0x00000000, //�Ƿ����ʲ����·�ʽ
	enmAssetUpdateMode_Plus      = 0x00000001, //����
	enmAssetUpdateMode_Minus     = 0x00000002, //����
};

//��ֵ��������7��������51�ң� �������Ƹ�ͨ��֧�����������У�����ͨ������һ��ͨ'

//��ֵ����
typedef int32_t 				RechargeChannel;
enum
{
	enmRechargeChannel_None         = 0x00000000,    //��Ч���ʲ����·�ʽ
	enmRechargeChannel_51Coin       = 0x00000001,    //51�ҳ�ֵ
	enmRechargeChannel_OnlineBank   = 0x00000002,    //������ֵ
	enmRechargeChannel_Caifutong    = 0x00000003,    //�Ƹ�ͨ
	enmRechargeChannel_Zhifubao     = 0x00000004,    //֧����
	enmRechargeChannel_Shenzhouxing = 0x00000005,    //������
	enmRechargeChannel_Tianxiatong  = 0x00000006,    //����ͨ
	enmRechargeChannel_Junwang      = 0x00000007,    //����һ��ͨ
};

typedef uint8_t 				RankListType;
enum
{
	enmRankType_InvalidType				= 0x00,		//��Ч�����а�����
	enmRankType_PopStarRankList			= 0x01,		//�������а�
	enmRankType_WealthRankList			= 0x02,		//�Ƹ����а�
	enmRankType_RoomRankList			= 0x03,		//�������а�
	enmRankType_GiftRankList			= 0x04,		//����֮�����а�
	enmRankType_StampRankList			= 0x05,		//ӡ��֮�����а�
};


/*
* vip�ȼ�״̬���壺���ֲ��䣬���ӣ�����
*/
typedef int32_t 				VipLevelStatus;
enum
{
	enmVipLevelStatus_Nochange  = 0,   //vip�ȼ�δ�����ı�
	enmVipLevelStatus_Plus      = 1,   //vip�ȼ�����
	enmVipLevelStatus_Minus     = 2,   //vip�ȼ�����
};


typedef uint8_t 				ENM_SystemMessageType;
enum
{
	enumSYSTEMMESSAGETYPE_SYSTEM	= 0x00,//ϵͳ��Ϣ
	enumSYSTEMMESSAGETYPE_TEXT		= 0x01,//���ı�
	enumSYSTEMMESSAGETYPE_BAOJI		= 0x20,//��������(���������𾴵�***������)
	enumSYSTEMMESSAGETYPE_INVALID	= 0xff,//��ʶ�����Ϣ
};

typedef uint8_t  				SysChannelType;
enum
{
	enumSysChannelType_Upgrade		= 0x00,//����Ƶ��
	enumSysChannelType_Degrade		= 0x01,//����Ƶ��
	enumSysChannelType_Ranklist		= 0x02,//���а�Ƶ��
	enumSysChannelType_Room			= 0x03,//������Ƶ��
	enumSysChannelType_Charge		= 0x04,//�����ʲ�Ƶ��
	enumSysChannelType_Invalid		= 0x0ff,//��Ч��Ƶ��
};

typedef uint8_t  				TitleID;
enum
{
	enumTitleID_Notify				= 0x01,//��ʾ
	enumTitleID_SysInfo				= 0x02,//ϵͳ��Ϣ
	enumTitleID_ChargeCenter		= 0x03,//179��ֵ����
	enumTitleID_Tips				= 0x04,//��ܰ��ʾ
	enumTitleID_Invalid				= 0xff,//��Ч��title
};

/*
* ��Ϣ��ȡ���Ͷ���
*/
typedef uint8_t 				MsgReadedType;
enum
{
	enmMsgReadedType_New     = 0x00,      //û�ж�ȡ
	enmMsgReadedType_Readed  = 0x01,      //�Ѿ���ȡ
	enmMsgReadedType_Total   = 0x02,      //���еģ������Ѿ���ȡ��δ��ȡ��
	enmMsgReadedType_Invalid = 0xFF,      //���Ϸ��Ķ�ȡ����
};

//����������Ϣ����
typedef int8_t 					UserInfoType;
enum
{
	enmUserInfoType_Invalid = 0x81,//��Чֵ
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

	//����room����ֶΣ�room notify��
	enmUserInfoType_Room_Titlelevel = 0x20,//uint16, �����ֻ�ȫ���ߵ�����֪ͨ��***����***Ϊ�ٹܣ�
	enmUserInfoType_Room_JiaZu = 0x21,//string
	enmUserInfoType_Room_ClientInfo = 0x22,//uint16
	enmUserInfoType_Room_Status = 0x23,
//uint16�����ֻ�ȫ���ߵ�����֪ͨ��***ȡ��***���󣿣�
};

typedef int8_t					UserStatusType;
enum
{
	enmUserStatusType_OK = 0,
	enmUserStatusType_Locked = 1,
};

/*
*  ϵͳ��������
*/
typedef int8_t      SysNoticeType;
enum
{
	enmSysNoticeType_None     = 0x00,    //��Ч��ϵͳ��������
	enmSysNoticeType_RoomChat = 0x01,    //��������������
	enmSysNoticeType_Roll     = 0x02,    //�ͻ��˹�������
	enmSysNoticeType_PopFrame = 0x03,    //�����򹫸�
};

/*
* 179�Ҹı���Դ
*/
typedef int8_t MoneyModifySource;
enum
{
	enmMoneyModifySource_None,         //��Ч���ʲ��޸���Դ
	enmMoneyModifySource_Artist,       //��Դ�����˺�̨
	enmMoneyModifySource_RoomMaster,   //��Դ��������̨
	enmMoneyModifySource_Business,     //��Դ����Ӫ��̨
};

/*
* ϵͳ�����Ƿ��Ѷ���ʾ
*/
typedef int8_t   SysNoticeFlag;
enum
{
	enmSysNoticeFlag_Unreaded  = 0x00,    //δ��
	enmSysNoticeFlag_Readed    = 0x01,    //�Ѷ�
};

/*
* ������Ϣ�ı乫�������
*/
enum
{
	enmRoomNotiType_invalid 	= 0x00,    //��Ч
	enmRoomNotiType_lock		= 0x01,    //��ͣ
	enmRoomNotiType_Capacity	= 0x02,    //�����ı�
	enmRoomNotiType_RankChange	= 0x03,    //�û�Ȩ�޸ı�
};

/*
* �����û�Ȩ�޸ı�����
*/
typedef int8_t	RankChangeType;
enum
{
	enmRoomRankChangeType_invalid 	= 0x00,    //��Ч
	enmRoomRankChangeType_up		= 0x01,    //����
	enmRoomRankChangeType_down		= 0x02,    //����
};

typedef uint8_t					UpdateDataType;
enum
{
	enmUpdateDataType_Room		= 0x00,			//���·�������
	enmUpdateDataType_Player	= 0x01,			//�����������
	enmUpdateDataType_CreateRoom= 0x02,			//��������
};

typedef uint32_t					PlayerSelfSetting;
enum
{
	enmSelfSeting_P2PShow_Mask		= 0x0180,//1����Ƶ����mask
	enmSelfSeting_P2PShow_Vip		= 0x0180,//1����Ƶ����->vip����
	enmSelfSeting_P2PShow_King		= 0x0100,//1����Ƶ����->�ʹ�
	enmSelfSeting_P2PShow_Close		= 0x0080,//1����Ƶ����->�ܾ��κ���
};

//״̬����
typedef uint16_t					MicType;
enum
{
	enmMicType_PublicMic		= 0x01,		//����
	enmMicType_PublicMicQueue	= 0x02,		//����
	enmMicType_PrivateMic		= 0x03,		//˽��
	enmMicType_P2PMic			= 0x04,     //һ��һ����
};

//�����ص���ʱ�����Ͷ���
typedef uint8_t UserTotalTimeType;
enum
{
	enmUserTotalTimeType_Invalid   = 0x00,   //��Ч�������ʱ������
	enmUserTotalTimeType_OnLine    = 0x01,   //�ܵ�����ʱ����ֻ���ɴ�������dbproxy��
	enmUserTotalTimeType_InRoom    = 0x02,   //�ܵ��ڷ����ʱ������roomserver����dbproxy��
	enmUserTotalTimeType_OnMike    = 0x03,   //�ܵ�����ʱ������roomserver����dbproxy��
};

//����ܱ�״̬ö�ٶ���
typedef int8_t  PwdProStatus;
enum
{
	enmPwdProStatus_Unset    = 0x00,     //��δ�����ܱ�
	enmPwdProStatus_Set      = 0x01,     //�Ѿ������ܱ�
};

typedef uint8_t	UpdatePacksackType;
enum
{
	enmUpdatePacksackType_Init	= 0x00,		//��һ�γ�ʼ���ҵ���Ʒ
	enmUpdatePacksackType_Add	= 0x01,		//�����Ʒ
	enmUpdatePacksackType_Del	= 0x02,		//ɾ����Ʒ
};

typedef uint8_t	EditBlackListType;
enum
{
	enmEditBlackListType_Invalid	= 0x00,  //��Ч
	enmEditBlackListType_Remove		= 0x01,  //ɾ��
	enmEditBlackListType_Add		= 0x02,  //���
};

/*
* ��Ӫ��̨��������
*/
typedef int8_t LockType;
enum
{
	enmLockType_Invalid   = 0x00,    //��Ч
	enmLockType_Player    = 0x01,       //�������
	enmLockType_IP        = 0x02,       //����IP
	enmLockType_Mac       = 0x03,       //����Mac��ַ
};

typedef uint8_t	EditPrivateType;
enum
{
	enmEditPrivateType_Invalid		= 0x00,  //��Ч
	enmEditPrivateType_Open			= 0x01,  //��
	enmEditPrivateType_Close		= 0x02,  //�ر�
};

typedef int32_t RoomAuditType;
enum
{
	enmRoomAuditType_Unused     = 0,       //δ����
	enmRoomAuditType_Pass       = 1,       //���ͨ��
	enmRoomAuditType_UnAudited  = 2,       //δ���
	enmRoomAuditType_Refused    = 3,       //�ٷ��ܾ��޸ģ� Ҳ�������û��ͨ��
};

typedef int32_t MicOperateType;
enum
{
	enmMicOperateType_Public_Up       	= 1,       //������
	enmMicOperateType_Private_Up  	  	= 2,       //˽����
	enmMicOperateType_Public_Dowm       = 3,       //������
	enmMicOperateType_Private_Down  	= 4,       //˽����
};

/*
* ���ؿ��ض���
*/
typedef int8_t JackpotFlag;
enum
{
	enmJackpotFlag_Close  = 0,      //���ؿ��ش��ڹر�״̬���ñ����Ľ�����Ч��
	enmJackpotFlag_Open   = 1,      //���ؿ��ش��ڴ�״̬���ñ����Ľ�����Ч��
};

typedef int8_t EnterRoomType;
enum
{
	enmEnterRoomType_Normal  = 0,      //��������
	enmEnterRoomType_Hid   = 1,      //�������
};

//����Ч������
typedef uint8_t	FlyEffectType;
enum
{
	enmFlyEffect_Close	= 0,	//����Ч���ر�
	enmFlyEffect_Open	= 1,	//����Ч����
};

/*
 * ����ϵͳ��ض���
 */
typedef uint8_t				TaskStatType;
enum
{
	enmTaskType_UnOpen	    = 0x00,          //δ��״̬
	enmTaskType_Unfinish	= 0x01,          //δ���״̬
	enmTaskType_UnReward    = 0x02,          //������ȡ״̬
	enmTaskType_Reward	    = 0x03,          //����ȡ����״̬
	enmTaskType_IsReward	= 0x04,          //����ȡ����״̬
	enmErrorType            = 0xff,          //��������
};

typedef uint8_t             OpType;
enum
{
	enmInvalidOpType     = 0x00,             //��Ч��������
	enmCountOpType       = 0x01,             //ͳ�Ʋ�������
	enmOnlyOpType        = 0x02,             //���β�������
};

typedef int32_t             TaskID;

typedef uint8_t             EmailStat;       //����״̬
enum
{
	enmNotCheckType      =0x00,                //δ��֤����
	enmCheckedType       =0x01,                //�Ѿ���֤����
};
//���ɼ��ص�������
#define MAX_TASK_COUNT     100

//һ�����ͬʱ���ϱ��������Ϊ��
#define MAX_ACTION_COUNT   10
typedef int32_t            ActionID  ;         //��ΪID
enum
{
	enmSendItemType      = 0x0001,             //��������
	enmSendColourBarType = 0x0002,             //���Ͳ���
	enmCheckEmail        = 0x0003,             //��֤����
	enmEditName   		 = 0x0004,             //�޸��ǳ�
	enmCollectRoom       = 0x0005,             //�ղط���
	enmRecharge          = 0x0006,             //��ֵ
	enmOnline            = 0x0007,             //����
};

typedef uint8_t        NickNameStat;            //�ǳ�״̬
enum
{
	enmNickName_NotAlterType        =0x00,      //δ�޸�
	enmNickName_AlreadyAlterType    =0x01,      //�Ѿ��޸�
	enmNickName_NoneType            =0xff,      //��Ч״̬
};

typedef uint8_t        RechargeStat;            //�ǳ�״̬
enum
{
	enmRecharge_NotAlterType        =0x00,      //δ��ֵ
	enmRecharge_OK                  =0x01,      //��ǰ��ֵ��
	enmRecharge_NoneType            =0xff,      //��Ч״̬
};

//�����ȼ�
typedef uint8_t	MagnateLevel;
enum
{
	enmMagnateLevel_0	= 0,	//�޵ȼ�
	enmMagnateLevel_1	= 1,	//1��
	enmMagnateLevel_2	= 2,	//2��
	enmMagnateLevel_3	= 3,    //3��
	enmMagnateLevel_4	= 4,    //4��
	enmMagnateLevel_5	= 5,    //5��
	enmMagnateLevel_6	= 6,    //6��
	enmMagnateLevel_7	= 7,    //7��
	enmMagnateLevel_8	= 8,    //8��
	enmMagnateLevel_9	= 9,    //9��
	enmMagnateLevel_10	= 10,   //10��
	enmMagnateLevel_11	= 11,   //֪��
	enmMagnateLevel_12	= 12,   //Ѳ��
	enmMagnateLevel_13	= 13,   //�ܶ�
	enmMagnateLevel_14	= 14,   //�ᶽ
	enmMagnateLevel_15	= 15,   //�ٸ�
	enmMagnateLevel_16	= 16,   //̫��
	enmMagnateLevel_17	= 17,   //����
	enmMagnateLevel_18	= 18,   //ة��
	enmMagnateLevel_19	= 19,   //����
	enmMagnateLevel_20	= 20,   //����
	enmMagnateLevel_21	= 21,   //����
	enmMagnateLevel_22	= 22,   //����
	enmMagnateLevel_23	= 23,   //����
	enmMagnateLevel_24	= 24,   //̫��
	enmMagnateLevel_25	= 25,   //�ʵ�
};


//ɳ����������
enum
{
	enmOperateSofa_Invalid	= 0,	//��Ч
	enmOperateSofa_Update	= 1,	//���µ����䵥��λ��ɳ��
	enmOperateSofa_ClearAll	= 2,	//������з���ɳ��
};

//�ʲ����²���gameserver����Ĵ�����
enum
{
	enmErrorCode_UnKnow			= 0xff,	//δ֪����
	enmErrorCode_Aguments		= 0x01,	//��������
	enmErrorCode_OverMaxMoney	= 0x02,	//�ʲ���������޶�
	enmErrorCode_NotEnoughMoney	= 0x03,	//�Ҳ���
	enmErrorCode_OffLine		= 0x04,	//��Ҳ�����
};

//����״̬
typedef uint8_t		OrderStatus;
enum
{
	enmOrderStatus_Processing	= 0x00,	//������
	enmOrderStatus_Accepted		= 0x01,	//��ͬ��
	enmOrderStatus_Refused		= 0x02,	//�Ѿܾ�
	enmOrderStatus_Good			= 0x03,	//�Ѻ���
	enmOrderStatus_Bad			= 0x04,	//�Ѳ���
	enmOrderStatus_NotVote		= 0x05,	//������
};

//��Ŀ״̬
typedef uint8_t		ProgramStatus;
enum
{
	enmProgramStatus_WaitingForStart			= 0x00,		//�ȴ���Ŀ��ʼ
	enmProgramStatus_FightingForTicket			= 0x01,		//��Ʊ�׶�
	enmProgramStatus_Enjoying					= 0x02,		//���ͽ�Ŀ�׶�
	enmProgramStatus_Voteing					= 0x03,		//ͶƱ�׶�
	enmProgramStatus_ShowResult					= 0x04,		//չʾ����׶�
};

typedef uint8_t		SongVoteResult;
enum
{
	enmSongVoteResult_Giveup		= 0x00,		//��Ȩ
	enmSongVoteResult_Good			= 0x01,		//��
	enmSongVoteResult_Bad			= 0x02,		//��
	enmSongVoteResult_NotVote		= 0x03,		//��δͶƱ
};

#endif /* PUBLIC_TYPEDEF_H_ */
