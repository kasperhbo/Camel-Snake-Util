//
// Created by Kasper de bruin on 27/03/2024.
//

#include "CertificateGeneratorWindow.h"
#include "../../Authenticator/touch_id_auth.h"
#include <iostream>
#include <Security/Security.h>
#include <Security/Authorization.h>

#include <vector>

#include <filesystem>
namespace HB::Utils::Certificates {


    CertificateGeneratorWindow::CertificateGeneratorWindow() {
        auth->executeCommandWithElevation(commands[0].command);
        auth->executeCommandWithElevation(commands[1].command);
        auth->executeCommandWithElevation(commands[2].command);
        auth->executeCommandWithElevation(commands[3].command);
    }

    CertificateGeneratorWindow::~CertificateGeneratorWindow() {

    }


    void CertificateGeneratorWindow::createWindow() {

    }

    void CertificateGeneratorWindow::show() {

    }

}