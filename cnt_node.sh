#!/bin/bash
git log --since=2018-01-01 --until=2020-12-31 --pretty=tformat: --numstat | awk '{ add += $1; subs += $2; loc += $1 - $2 } END { printf ("lines: %s, removed lines: %s, total lines: %s\n", add, subs, loc) }'
