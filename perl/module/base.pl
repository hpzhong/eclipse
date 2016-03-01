#!/usr/bin/env perl -w
use strict;
use 5.014;
use File::Basename;
my $name = basename("/foo/bar/baz.txt");
my $name1 = basename($ARGV[0]);
my $sdir = dirname("/foo/bar/baz.txt");
say $name;
say $name1;
say $sdir;
