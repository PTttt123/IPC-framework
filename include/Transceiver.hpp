/*
 * @Author: Longhao.Chen <Longhao.Chen@outlook.com>
 * @Date: 2023-09-19 20:54:20
 * @LastEditors: Longhao.Chen <Longhao.Chen@outlook.com>
 * @FilePath: /IPC-framework/include/Transceiver.hpp
 * @Description: 抽象收发器
 * Copyright (c) 2023 by Longhao.Chen, All Rights Reserved. 
 */
#ifndef HEADER_TRANSCEIVER
#define HEADER_TRANSCEIVER
#include <string>
#include <Message.hpp>

namespace Transceiver
{

// 只能接收信息，接收信息是可靠的
class AbstractReceiver {
    private:
	// 接收器名
	std::string name;

    public:
	// 传入接收器名
	AbstractReceiver(std::string name);
	// 调用此函数开始接收，未接收到时会阻塞，返回接收到的字节数
	// 传入缓冲区指针和缓冲区字节数
	virtual long receive(char *buf, long size) = 0;
	virtual long receive(Message::AbstractMessage &);
	// 返回接收器名
	std::string getName() const;
};

// 只能发送信息，发送信息是可靠的
class AbstractTransmitter {
    private:
	// 对应的接收器名
	std::string dest;

    public:
	// 传入目标接收器的名
	AbstractTransmitter(std::string dest);
	// 调用此函数开始发送，会阻塞，返回发送的字节数
	// 传入缓冲区和总字节数
	virtual long send(const char *buf, long size) = 0;
	virtual long send(const Message::AbstractMessage &);
	// 返回目标接收器名
	std::string getDest() const;
};

// 可以全双工的收发信息，收发信息是可靠的
class AbstractTransceiver : virtual public AbstractReceiver,
			    virtual public AbstractTransmitter {
    public:
	AbstractTransceiver(std::string name, std::string dest);
};
};
#endif