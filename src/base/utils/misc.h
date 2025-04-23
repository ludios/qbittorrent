/*
 * Bittorrent Client using Qt and libtorrent.
 * Copyright (C) 2006  Christophe Dumez <chris@qbittorrent.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link this program with the OpenSSL project's "OpenSSL" library (or with
 * modified versions of it that use the same license as the "OpenSSL" library),
 * and distribute the linked executables. You must obey the GNU General Public
 * License in all respects for all of the code used other than "OpenSSL".  If you
 * modify file(s), you may extend this exception to your version of the file(s),
 * but you are not obligated to do so. If you do not wish to do so, delete this
 * exception statement from your version.
 */

#pragma once

#include <QtTypes>

#include "base/pathfwd.h"

class QString;
class QStringView;

/*  Miscellaneous functions that can be useful */
namespace Utils::Misc
{
    enum class SizeUnit
    {
        Byte,
        KiloByte,
        MegaByte,
        GigaByte,
        TeraByte,
        PetaByte,
        ExaByte
    };

    enum class TimeResolution
    {
        Seconds,
        Minutes
    };

    QString parseHtmlLinks(const QString &rawText);

    QString osName();
    QString boostVersionString();
    QString libtorrentVersionString();
    QString opensslVersionString();
    QString zlibVersionString();

    QString unitString(SizeUnit unit, bool isSpeed = false);

    // return the best user friendly storage unit (B, KB, MB, GB, TB)
    // value must be given in bytes
    QString friendlyUnit(qint64 bytes, bool isSpeed = false, int precision = -1);
    QString friendlyUnitCompact(qint64 bytes);
    int friendlyUnitPrecision(SizeUnit unit);
    qint64 sizeInBytes(qreal size, SizeUnit unit);

    bool isPreviewable(const Path &filePath);
    bool isTorrentLink(const QString &str);

    // Take a number of seconds and return a user-friendly
    // time duration like "1d 2h 10m".
    QString userFriendlyDuration(qlonglong seconds, qlonglong maxCap = -1, TimeResolution resolution = TimeResolution::Minutes);

    QString languageToLocalizedString(QStringView localeStr);
}
