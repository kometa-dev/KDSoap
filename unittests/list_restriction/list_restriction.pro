## This file is part of the KD Soap library.
##
## SPDX-FileCopyrightText: 2019-2021 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
##
## SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDAB-KDSoap OR LicenseRef-KDAB-KDSoap-US
##
## Licensees holding valid commercial KD Soap licenses may use this file in
## accordance with the KD Soap Commercial License Agreement provided with
## the Software.
##
## Contact info@kdab.com if any conditions of this licensing are not clear to you.
##

include( $${TOP_SOURCE_DIR}/unittests/unittests.pri )

QT += network xml
SOURCES = test_list_restriction.cpp
test.target = test
test.commands = ./$(TARGET)
test.depends = $(TARGET)
QMAKE_EXTRA_TARGETS += test


LIBS += -L$${TOP_BUILD_DIR}/lib $${KDWSDL2CPP_LIBS}
unix:PRE_TARGETDEPS += $${TOP_BUILD_DIR}/lib/libkdwsdl2cpp_lib.a
