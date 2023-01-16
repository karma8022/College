#! /bin/csh

echo "APT_ARCH=$APT_ARCH";
echo "APT_HOME=$APT_HOME";

if ($#argv == 0) then

    if ($APT_ARCH == "MAC") then
        java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar
    else
        java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar
    endif

else if ($#argv == 1) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1]
    endif

else if ($#argv == 2) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2]
    endif

else if ($#argv == 3) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3]
    endif

else if ($#argv == 4) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4]
    endif

else if ($#argv == 5) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5]
    endif

else if ($#argv == 6) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6]
    endif

else if ($#argv == 7) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7]
    endif

else if ($#argv == 8) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8]
    endif

else if ($#argv == 9) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8] $argv[9]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8] $argv[9]
    endif

else if ($#argv == 10) then

    if ($APT_ARCH == "MAC") then
            java -Duser.language=en -Duser.region=US -Xmx2048M -Xdock:name="IGNORE" -Xdock:icon=$APT_HOME/Aperture\ Photometry\ Tool.app/Contents/Resources/APT.icns -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8] $argv[9] $argv[10]
    else
            java -Duser.language=en -Duser.region=US -Xmx2048M -jar $APT_HOME/APT.jar $argv[1] $argv[2] $argv[3] $argv[4] $argv[5] $argv[6] $argv[7] $argv[8] $argv[9] $argv[10]
    endif

else

    echo "Too many arguments given on command line; quitting...";

endif
