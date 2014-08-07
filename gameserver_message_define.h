/**************************************************************
* filename: gameserver_message_define.h
* date:     2013-01-11 13:52
* author:   jackie
* purpose:  客户端小游戏服务器消息及其结构定义
            EntityType: 0x15,也就是21
**************************************************************/

#ifndef __GAMESERVER_MESSAGE_DEFINE_H
#define __GAMESERVER_MESSAGE_DEFINE_H

#include "common/common_string.h"
#include "frame_namespace.h"
#include "frame_typedef.h"
#include "frame_msg_impl.h"
#include "public_typedef.h"
#include "common/common_codeengine.h"
#include "frame_msg_impl.h"
#include "common/common_singleton.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

/*
* 游戏服务器向后端server发送获取用户基本信息请求
*/
#define MSGID_GAMESVR_GET_ROLE_BASEINFO_REQ   0x00111501
class CGameSvrGetRoleInfoReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID   nRoleID;

public:
	CGameSvrGetRoleInfoReq()
	{
		nRoleID = enmInvalidRoleID;
	}
	virtual ~CGameSvrGetRoleInfoReq(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{	
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d}\n", nRoleID);
		offset = (uint32_t)strlen(buf);
	}
};

/*
* 后端server向游戏服务器发送获取用户信息响应
*/
#define MSGID_SVRGAME_GET_ROLE_BASEINFO_RESP  0x00121501
class CSvrGameGetRoleBaseInfoResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;
	int32_t n179ID;
	RoleID  nRoleID;
	CString<MaxRoleNameLength> strName;
	VipLevel  nVipLevel;
	MagnateLevel nMagnateLevel;
	uint32_t  nMoney;
	uint32_t  nGold;
	CString<MaxThumbLength> strThumb;
public:
	CSvrGameGetRoleBaseInfoResp()
	{
		nResult = S_OK;
		n179ID = 0;
		nRoleID = enmInvalidRoleID;
		strName.Initialize();
		nVipLevel = enmInvalidVipLevel;
		nMagnateLevel = 0;
		nMoney = 0;
		nGold = 0;
		strThumb.Initialize();
	}
	virtual ~CSvrGameGetRoleBaseInfoResp(){}

public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, n179ID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strName.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nVipLevel);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMagnateLevel);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nMoney);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGold);
		if(0 > ret)
		{
			return ret;
		}
		ret = strThumb.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Decode(buf, size, offset, n179ID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strName.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nVipLevel);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMagnateLevel);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nMoney);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGold);
		if(0 > ret)
		{
			return ret;
		}
		ret = strThumb.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=0x%08X, n179ID=%d, nRoleID=%d, szName=%s, nVipLevel=%d, nMagnateLevel=%d, nMoney=%d, nGold=%u"
				", szThumb=%s}\n",
			nResult, n179ID, nRoleID, strName.GetString(), nVipLevel, nMagnateLevel, nMoney, nGold, strThumb.GetString());
		offset = strlen(buf);
	}
};

//** 更新用户资产请求
#define MSGID_GAMESVR_UPDATE_ASSET_REQ   0x00111503
class CGameSvrUpdateAssetReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	RoleID  nRoleID;  //用户179UIN
	UpdateAssetOperate  nOpMode; //资产操作方式，1为增加，2为减少
	AssetType  nAssetType;      //1为179币，2为服务器内部使用【游戏不用关心】，3为金豆
	uint32_t   nAmount;        //更新的数量
public:
	CGameSvrUpdateAssetReq()
	{	
		nRoleID = enmInvalidRoleID;
		nOpMode = enmInvalidUpdateAssetOperate;
		nAssetType = enmInvalidAssetType;
		nAmount = 0;
	}
	virtual ~CGameSvrUpdateAssetReq()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nOpMode);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAssetType);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nOpMode);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAssetType);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nOpMode=%d, nAssetType=%d, nAmount=%d}\n",
			nRoleID, nOpMode, nAssetType, nAmount);
		offset = (uint32_t)strlen(buf);
	}
};

//** 游戏页面更新资产响应
#define MSGID_SVRGAME_UPDATE_ASSET_RESP  0x00121503
class CSvrGameUpdateAssetResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;
public:
	CSvrGameUpdateAssetResp()
	{
		nResult = 0;
	}
	virtual ~CSvrGameUpdateAssetResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{	
		sprintf(buf + offset, "{nResult=%d}\n", nResult);
		offset = (uint32_t)strlen(buf);
	}
};

//13. * 获取金豆兑换记录请求
#define MESGIID_GAMESVR_GET_EXCHANGE_LOG_REQ  0x00111504
class CGameSvrGetExchangeLogReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nRoleID; //角色ID
	int32_t nBeginTime;  //开始时间
	int32_t nEndTime; //结束时间
	int32_t nPage; //页码
	int32_t nPageSize;  //每页行数
public:
	CGameSvrGetExchangeLogReq()
	{
		nRoleID = enmInvalidRoleID;
		nBeginTime = 0;
		nEndTime = 0;
		nPage = 0;
		nPageSize = 0;
	}
	virtual ~CGameSvrGetExchangeLogReq()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nBeginTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPage);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPageSize);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nBeginTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPage);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPageSize);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nBeginTime=%d, nEndTime=%d, nPage=%d, nPageSize=%d}\n",
			nRoleID, nBeginTime, nEndTime, nPage, nPageSize);
		offset = (uint32_t)strlen(buf);
	}
};

//14. * 获取金豆兑换记录响应
#define MESGIID_SVRGAME_GET_EXCHANGE_LOG_RESP  0x00121504
class CSvrGameGetExchangeLogResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult; //查询结果
	int32_t nTotalCount; //总条数，如果ROLEID为0，则是所有满足时间条件的记录，
	// ROLEID如果有效，则是该用户满足时间条件的所有记录的条数
	int32_t nCount;        //获取到的记录的条数
	int32_t arr179ID[MaxExchangeLogCountPerTime];
	int32_t arrExchangeTime[MaxExchangeLogCountPerTime]; //兑换时间
	int32_t arrItemID[MaxExchangeLogCountPerTime]; //兑换类型
	int32_t arrExchangeNum[MaxExchangeLogCountPerTime]; //兑换数量
	int32_t arrAmount[MaxExchangeLogCountPerTime]; //消费金额
public:
	CSvrGameGetExchangeLogResp()
	{
		nResult = 0;
		nTotalCount = 0;
		nCount = 0;
		memset(arr179ID, 0, sizeof(arr179ID));
		memset(arrExchangeTime, 0, sizeof(arrExchangeTime));
		memset(arrItemID, 0, sizeof(arrItemID));
		memset(arrExchangeNum, 0, sizeof(arrExchangeNum));
		memset(arrAmount, 0, sizeof(arrAmount));
	}
	virtual ~CSvrGameGetExchangeLogResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nTotalCount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nCount; ++i)
		{
			ret = CCodeEngine::Encode(buf, size, offset, arr179ID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrExchangeTime[i]);
			if(0  > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrItemID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrExchangeNum[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Encode(buf, size, offset, arrAmount[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nTotalCount);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nCount);
		if(0 > ret)
		{
			return ret;
		}
		for(int32_t i=0; i<nCount; ++i)
		{
			ret = CCodeEngine::Decode(buf, size, offset, arr179ID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrExchangeTime[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrItemID[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrExchangeNum[i]);
			if(0 > ret)
			{
				return ret;
			}
			ret = CCodeEngine::Decode(buf, size, offset, arrAmount[i]);
			if(0 > ret)
			{
				return ret;
			}
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nTotalCount=%d, nCount=%d", 
			nResult, nTotalCount, nCount);
		offset = (uint32_t)strlen(buf);

		if(0 > nResult)
		{
			sprintf(buf + offset, "}\n");
			offset = (uint32_t)strlen(buf);
			return;
		}

		for(int32_t i=0; i<nCount; ++i)
		{
			sprintf(buf + offset, "{arr179ID[%d]=%d, arrExchangeTime[%d]=%d, arrItemID[%d]=%d, arrExchangeNum[%d]=%d, arrAmount[%d]=%d}, ", 
				i, arr179ID[i],
				i, arrExchangeTime[i], 
				i, arrItemID[i], 
				i, arrExchangeNum[i], 
				i, arrAmount[i]);
			offset = (uint32_t)strlen(buf);
		}
		offset = (uint32_t)strlen(buf);

		sprintf(buf + offset, "}\n");
		offset = (uint32_t)strlen(buf);
	}
};

//15. * 金豆兑换请求
#define MESGIID_GAMESVR_CURRENCY_EXCHANGE_REQ  0x00111505
class CGameSvrCurrencyExchangeReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nRoleID; //角色ID
	int32_t nItemID; //道具ID
	int32_t nNumber; //数量
	int32_t nPrice; //道具价格
	int32_t nAmount; //兑换总金额
public:
	CGameSvrCurrencyExchangeReq()
	{
		nRoleID = enmInvalidRoleID;
		nItemID = enmInvalidItemID;
		nNumber = 0;
		nPrice = 0;
		nAmount = 0;
	}
	virtual ~CGameSvrCurrencyExchangeReq()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{	
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nNumber);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nPrice);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nItemID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nNumber);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nPrice);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nItemID=%d, nNumber=%d, nPrice=%d, nAmount=%d}\n", 
			nRoleID, nItemID, nNumber, nPrice, nAmount);
		offset = (uint32_t)strlen(buf);
	}
};

//16.金豆兑换响应
#define MESGIID_SVRGAME_CURRENCY_EXCHANGE_RESP 0x00121505
class CSvrGameCurrencyExchangeResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;   //处理结果，为0表示正确，小于0表示出错
	int32_t nRoleID;   //用户179UIN
	uint32_t n179Coin;  //用户的179币的数量
	uint32_t nGoldBean; //用户金豆的数量
public:
	CSvrGameCurrencyExchangeResp()
	{
		nResult = S_OK;
		nRoleID = enmInvalidRoleID;
		n179Coin = 0;
		nGoldBean = 0;
	}
	virtual ~CSvrGameCurrencyExchangeResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		if(0 > nResult)
		{
			return S_OK;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, n179Coin);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGoldBean);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, n179Coin);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGoldBean);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nRoleID=%d, n179Coin=%u, nGoldBean=%u}\n",
			nResult, nRoleID, n179Coin, nGoldBean);
		offset = (uint32_t)strlen(buf);
	}
};

//游戏中奖通知：通知给客户端在线的所有用户
#define MESGID_GAMESVR_AWARD_MSG_REQ   0x00111506
class CGameSvrAwardMsgReq: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nRoleID; //角色ID
	CString<MaxRoleNameLength> strRoleName;
	int32_t nGameID;  //游戏ID 用来记录不同游戏中奖信息
	CString<MaxGameNameLength>    strGameName; //
	int32_t nAmount; //中奖金额
public:
	CGameSvrAwardMsgReq()
	{
		nRoleID = enmInvalidRoleID;
		strRoleName.Initialize();
		nGameID = 0;
		strGameName.Initialize();
		nAmount = 0;
	}
	virtual ~CGameSvrAwardMsgReq()
	{
		
	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nGameID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strGameName.MessageEncode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strRoleName.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nGameID);
		if(0 > ret)
		{
			return ret;
		}
		ret = strGameName.MessageDecode(buf, size, offset);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, strRoleName=%s, nGameID=%d, strGameName=%s, nAmount=%d}\n",
			nRoleID, strRoleName.GetString(), nGameID, strGameName.GetString(), nAmount);
		offset = (uint32_t)strlen(buf);
	}
};

//18. 中奖消息接口响应
#define MESGID_SVRGAME_AWARD_MSG_RESP 0x00121506
class CSvrGameAwardMsgResp: public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;
public:
	CSvrGameAwardMsgResp()
	{
		nResult = 0;
	}
	virtual ~CSvrGameAwardMsgResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d}\n", nResult);
		offset = (uint32_t)strlen(buf);
	}
};


//获取用户15天之内的充值金额请求
#define MESGID_SVRGAME_GET_RECHARGE_MSG_REQ 0x00111507
class CGameSvrGetRechargeMsgReq:public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t  nRoleID;
	int32_t  nBeginTime;
	int32_t  nEndTime;
public:
	CGameSvrGetRechargeMsgReq()
	{
		nRoleID = 0;
		nBeginTime = 0;
		nEndTime = 0;
	}
	virtual ~CGameSvrGetRechargeMsgReq()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nBeginTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nRoleID);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nBeginTime);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nEndTime);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nRoleID=%d, nBeginTime=%d, nEndTime=%d}\n", nRoleID, nBeginTime, nEndTime);
		offset = (uint32_t)strlen(buf);
	}

};

//获取用户15天之内的充值金额响应
#define MESGID_SVRGAME_GET_RECHARGE_MSG_RESP 0x00121507
class CGameSvrGetRechargeMsgResp:public IMsgBody
{
	SIZE_INTERFACE();
public:
	int32_t nResult;
	int32_t nRechargeAmount;
public:
	CGameSvrGetRechargeMsgResp()
	{
		nResult = S_OK;
		nRechargeAmount = 0;
	}
	virtual ~CGameSvrGetRechargeMsgResp()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Encode(buf, size, offset, nRechargeAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nResult);
		if(0 > ret)
		{
			return ret;
		}
		ret = CCodeEngine::Decode(buf, size, offset, nRechargeAmount);
		if(0 > ret)
		{
			return ret;
		}
		return S_OK;
	}
	virtual void Dump(char *buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "{nResult=%d, nRechargeAmount=%d}\n", nResult, nRechargeAmount);
		offset = (uint32_t)strlen(buf);
	}
};


MESSAGEMAP_DECL_BEGIN(gameserver)

MESSAGEMAP_DECL_MSG(MSGID_GAMESVR_GET_ROLE_BASEINFO_REQ, (new CGameSvrGetRoleInfoReq()))
MESSAGEMAP_DECL_MSG(MSGID_SVRGAME_GET_ROLE_BASEINFO_RESP, (new CSvrGameGetRoleBaseInfoResp()))

MESSAGEMAP_DECL_MSG(MSGID_GAMESVR_UPDATE_ASSET_REQ, (new CGameSvrUpdateAssetReq()))
MESSAGEMAP_DECL_MSG(MSGID_SVRGAME_UPDATE_ASSET_RESP, (new CSvrGameUpdateAssetResp()))

MESSAGEMAP_DECL_MSG(MESGIID_GAMESVR_GET_EXCHANGE_LOG_REQ, (new CGameSvrGetExchangeLogReq()))
MESSAGEMAP_DECL_MSG(MESGIID_SVRGAME_GET_EXCHANGE_LOG_RESP, (new CSvrGameGetExchangeLogResp()))

MESSAGEMAP_DECL_MSG(MESGIID_GAMESVR_CURRENCY_EXCHANGE_REQ, (new CGameSvrCurrencyExchangeReq()))
MESSAGEMAP_DECL_MSG(MESGIID_SVRGAME_CURRENCY_EXCHANGE_RESP, (new CSvrGameCurrencyExchangeResp()))

MESSAGEMAP_DECL_MSG(MESGID_GAMESVR_AWARD_MSG_REQ, (new CGameSvrAwardMsgReq()))
MESSAGEMAP_DECL_MSG(MESGID_SVRGAME_AWARD_MSG_RESP, (new CSvrGameAwardMsgResp()))

MESSAGEMAP_DECL_MSG(MESGID_SVRGAME_GET_RECHARGE_MSG_REQ, (new CGameSvrGetRechargeMsgReq()))
MESSAGEMAP_DECL_MSG(MESGID_SVRGAME_GET_RECHARGE_MSG_RESP, (new CGameSvrGetRechargeMsgResp()))

MESSAGEMAP_DECL_END()


FRAME_NAMESPACE_END


#endif
