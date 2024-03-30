//
// Created by Kasper de bruin on 27/03/2024.
//

#ifndef CAMELSNAKEUTIL_TOUCH_ID_AUTH_H
#define CAMELSNAKEUTIL_TOUCH_ID_AUTH_H
#ifndef TOUCHIDAUTHENTICATOR_H
#define TOUCHIDAUTHENTICATOR_H

#include <functional>
#include <string>
#include <vector>
#include <Security/Authorization.h>
#include <Security/AuthorizationTags.h>

class TouchIDAuthenticator {
//public:
//    using AuthCallback = std::function<void(bool success)>;
//    using CommandCallback = std::function<void(const std::string&)>;
//
//    void authenticateAndRun(const AuthCallback& callback, const std::string& command);
//    void runCommandWithElevatedPrivileges(const std::string& command) ;
//
//    void createFolderElevated(const std::string& command);


private:
    AuthorizationRef authRef;

public:
    TouchIDAuthenticator() : authRef(nullptr) {}

    ~TouchIDAuthenticator();

    void initializeAuthorization() ;

    void executeCommandWithElevation(const std::string& command);

};

#endif // TOUCHIDAUTHENTICATOR_H

#endif //CAMELSNAKEUTIL_TOUCH_ID_AUTH_H
