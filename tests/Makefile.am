# Copyright (C) 2014 Giovanni [dacav] Simoni
#                    <simgidacav@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
AM_CXXFLAGS = -I../src -std=c++11 -Wall -Werror -pthread -g
AM_LDFLAGS = -L../src

check_PROGRAMS = \
	interc_base \
	network_bytes \
	queue_base \
	visualizer_base \
	lookup_adv \
	lookup_base

TESTS = $(check_PROGRAMS)

queue_base_SOURCES = queue_base.cc
queue_base_LDADD = -lhackermap
queue_base_DEPENDENCIES = $(srcdir)/../src/libhackermap.a

interc_base_SOURCES = interc_base.cc
interc_base_LDADD = -lhackermap
interc_base_DEPENDENCIES = $(srcdir)/../src/libhackermap.a

network_bytes_SOURCES = network_bytes.cc
network_bytes_LDADD = -lhackermap
network_bytes_DEPENDENCIES = $(srcdir)/../src/libhackermap.a

lookup_base_SOURCES = lookup_base.cc
lookup_base_LDADD = -lhackermap
lookup_base_DEPENDENCIES = $(srcdir)/../src/libhackermap.a

visualizer_base_SOURCES = visualizer_base.cc
visualizer_base_LDADD = -lhackermap
visualizer_base_DEPENDENCIES = $(srcdir)/../src/libhackermap.a

lookup_adv_SOURCES = lookup_adv.cc
lookup_adv_LDADD = -lhackermap
lookup_adv_DEPENDENCIES = $(srcdir)/../src/libhackermap.a
