/*
 * account_message_define.h
 *
 *  Created on: Jun 30, 2014
 *      Author: jimm
 */

#ifndef ACCOUNT_MESSAGE_DEFINE_H_
#define ACCOUNT_MESSAGE_DEFINE_H_

#include "common/common_errordef.h"
#include "frame_namespace.h"
#include "frame_msg_impl.h"
#include "frame_typedef.h"
#include "public_typedef.h"
#include <string.h>

FRAME_NAMESPACE_BEGIN

#define MSGID_GETACCOUNTINFO_REQ		0x00110C01
class CGetAccountInfoReq : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetAccountInfoReq()
	{
		nAccountID = enmInvalidAccountID;
	}
	virtual ~CGetAccountInfoReq()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}


		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nAccountID=%d}\n", nAccountID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	AccountID			nAccountID;
};


#define MSGID_GETACCOUNTINFO_RESP		0x00120C01
class CGetAccountInfoResp : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CGetAccountInfoResp()
	{
		nAccountID = enmInvalidAccountID;
	}
	virtual ~CGetAccountInfoResp()
	{

	}
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Encode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}


		return S_OK;
	}
	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		int32_t ret = S_OK;
		ret = CCodeEngine::Decode(buf, size, offset, nAccountID);
		if (0 > ret)
		{
			return ret;
		}

		return S_OK;
	}
	void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nAccountID=%d}\n", nAccountID);
	    offset = (uint32_t)strlen(buf);
	}
public:
	uint16_t			nResult;
	RoleID				nRoleID;
	AccountID			nAccountID;
	int8_t				nUidLen;
	char				arrEmail[MAX_EMAIL_LEN];
	int8_t				arrSessionKey[MAX_SESSIONKEY_LEN];
	int8_t				nSessionKeyLen;
};


FRAME_NAMESPACE_END


#endif /* ACCOUNT_MESSAGE_DEFINE_H_ */
