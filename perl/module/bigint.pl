#!/usr/bin/env perl -w
use strict;
use 5.014;
use Math::BigInt;
my $value = Math::BigInt->new(2);

$value->bpow(1000);
say $value->bstr;
say 2**1000;

