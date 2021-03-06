#!/bin/sh -e


##########################################################################
#   Function description:
#       Pause until user presses return
##########################################################################

pause()
{
    local junk
    
    printf "Press return to continue..."
    read junk
}

pkg=$(basename $(pwd))

cd ..
printf "Importing $pkg...\n"
pwd
git pull
git pull -r
git add $pkg

printf "Add $pkg to Makefile.\n"
pause
vi Makefile
git add Makefile

git status
pause

msg=`awk -F = '$1 ~ "^COMMENT" { print $2 }' $pkg/Makefile`
git commit -m "Add $pkg: $msg"
git log || true
printf "Push commit? y/[n] "
read commit
if [ 0$commit = 0y ]; then
    git push
fi
