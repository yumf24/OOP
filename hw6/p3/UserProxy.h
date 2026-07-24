#pragma once
#include <string>
#include <iostream>
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"
#include "User.h"

class UserProxy {
private:
    EncryptStrategy* _encStr;
    VerificationStrategy* _verStr;
    RealUser* _ruser;
public:
    UserProxy(RealUser* ruser, EncryptStrategy* encStr, VerificationStrategy* verStr):
    _encStr(encStr), _verStr(verStr), _ruser(ruser) {}

    void sendMessage(std::string mes) {
        std::string enc_mes = _encStr->encode(mes);
        _ruser->sendMessage(enc_mes);
        std::cout << _verStr->verify(mes) << std::endl;
    }
};