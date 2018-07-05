%define _build_arch %(uname -i)
%define _zip_file common-base.zip

# Turn off the brp-python-bytecompile script
%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-python-bytecompile[[:space:]].*$!!g')
# disable jar repacking
%global __os_install_post %(echo '%{__os_install_post}' | sed -e 's!/usr/lib[^[:space:]]*/brp-java-repack-jars[[:space:]].*$!!g')

#
# AWIPS II CAVE/EDEX common base Spec File
#
Name: awips2-common-base
Summary: AWIPS II Edex
Version: %{_component_version}
Release: %{_component_release}%{?dist}
Group: AWIPSII
BuildRoot: %{_build_root}
BuildArch: %{_build_arch}
URL: N/A
License: N/A
Distribution: N/A
Vendor: %{_build_vendor}
Packager: %{_build_site}

AutoReq: no
Provides: awips2-common-base
Requires: awips2-base
Requires: netcdf >= 4.0.0
Requires: netcdf-devel >= 4.0.0

BuildRequires: awips2-ant
BuildRequires: awips2-java

%description
AWIPS II Common Base - Contains common plugins utilized by EDEX.

%prep
# Ensure that a "buildroot" has been specified.
if [ "%{_build_root}" = "" ]; then
   echo "ERROR: A BuildRoot has not been specified."
   echo "FATAL: Unable to Continue ... Terminating."
   exit 1
fi

if [ -d %{_build_root} ]; then
   rm -rf %{_build_root}
fi
/bin/mkdir -p %{_build_root}
if [ $? -ne 0 ]; then
   exit 1
fi

%build
_build_xml=build.xml
BUILD_EDEX=%{_baseline_workspace}/build.edex
EDEX_DIST=${BUILD_EDEX}/edex/dist

cd ${BUILD_EDEX}
/awips2/ant/bin/ant -f ${_build_xml} \
   -Dbuild.arch=x86_64 \
   -Dfeature=com.raytheon.uf.common.base.feature \
   -Duframe.eclipse=%{_uframe_eclipse} \
   clean \
   build \
   clean
if [ $? -ne 0 ]; then
   exit 1
fi

%install
BUILD_EDEX=%{_baseline_workspace}/build.edex
EDEX_DIST=${BUILD_EDEX}/edex/dist

/usr/bin/unzip ${EDEX_DIST}/common-base.zip -d %{_build_root}
if [ $? -ne 0 ]; then
   exit 1
fi

%post

%preun
if [ -d /awips2/.edex ]; then
   rm -rf /awips2/.edex
fi

%clean
rm -rf ${RPM_BUILD_ROOT}

%files
%defattr(644,awips,fxalpha,755)
/awips2/edex/*
