#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

/mnt/c/Program\ Files\ \(x86\)/Steam/steamapps/common/DayZ\ Tools/Bin/WorkDrive/WorkDrive.exe /Mount P \
  "$(wslvar USERPROFILE)\Documents\DayZData"

cmd.exe /c mkdir "C:\Program Files (x86)\Steam\steamapps\common\DayZ\VRP\weapons"
cmd.exe /c mklink /J "C:\Program Files (x86)\Steam\steamapps\common\DayZ\VRP\weapons\StunBaton" "$(wslpath -w "$SCRIPT_DIR/../mod")"
cmd.exe /c mkdir "P:\VRP\weapons"
cmd.exe /c mklink /J "P:\VRP\weapons\StunBaton" "$(wslpath -w "$SCRIPT_DIR/../mod")"

# Community Framework

cmd.exe /c mklink /J "C:\Program Files (x86)\Steam\steamapps\common\DayZ\JM" "$(wslpath -w "$SCRIPT_DIR/../../CommunityFramework/JM")"

cmd.exe /c mklink /J "P:\JM" "$(wslpath -w "$SCRIPT_DIR/../../CommunityFramework/JM")"

cmd.exe /c mklink /J "P:\JM\COT" "$(wslpath -w "$SCRIPT_DIR/../../DayZ-CommunityOnlineTools/JM/COT")"