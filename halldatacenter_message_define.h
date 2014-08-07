/*
 * halldatacenter_message_define.h
 *
 *  Created on: 2013-1-17
 *      Author: luocj
 */

#ifndef HALLDATACENTER_MESSAGE_DEFINE_H_
#define HALLDATACENTER_MESSAGE_DEFINE_H_

#include "frame_namespace.h"
#include "frame_typedef.h"
#include "common/common_codeengine.h"
#include "./public_typedef.h"
#include "common/common_api.h"
#include <stdio.h>

FRAME_NAMESPACE_BEGIN

#define MSGID_HDTH_REBULIDHALLFINISH_NOTI		0x00131401
class CRebulidHallFinishNoti : public IMsgBody
{
	SIZE_INTERFACE();
public:
	CRebulidHallFinishNoti()
	{
	}

	virtual ~CRebulidHallFinishNoti()
	{

	}
public:
	virtual int32_t MessageEncode(uint8_t* buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual int32_t MessageDecode(const uint8_t *buf, const uint32_t size, uint32_t& offset)
	{
		return S_OK;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		sprintf(buf + offset, "MsgBody={nothing}\n");
		offset = (uint32_t) strlen(buf);
	}
};

MESSAGEMAP_DECL_BEGIN(halldatacenter)

MESSAGEMAP_DECL_MSG(MSGID_HDTH_REBULIDHALLFINISH_NOTI, (new CRebulidHallFinishNoti()))

MESSAGEMAP_DECL_END()

FRAME_NAMESPACE_END
#endif /* HALLDATACENTER_MESSAGE_DEFINE_H_ */
