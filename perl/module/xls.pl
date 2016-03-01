#!/usr/bin/env perl -w
use strict;
use 5.014;
use Spreadsheet::WriteExcel;

my $workbook = Spreadsheet::WriteExcel->new("perl.xls");

my $worksheet = $workbook->add_worksheet();
$worksheet->write('A1', "Hello Excel!");
$worksheet->write(0,0, "hello Excel!");

