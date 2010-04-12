eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;

$iorbase = "server.ior";
$testbase = "test";

my $server = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $client = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";

$server_iorfile = $server->LocalFile ($iorbase);
$client_iorfile = $client->LocalFile ($iorbase);
$server->LocalFile ($testbase);
$server->DeleteFile($iorbase);
$server->DeleteFile($testbase);
$client->DeleteFile($iorbase);

$SV = $server->CreateProcess ("server", "-o $server_iorfile");
$CL = $client->CreateProcess ("client", "-k $client_iorfile");

$server_status = $SV->Spawn ();

if ($server_status != 0) {
    print STDERR "ERROR: server returned $server_status\n";
    exit 1;
}

if ($server->WaitForFileTimed ($iorbase,
                               $server->ProcessStartWaitInterval()) == -1) {
    print STDERR "ERROR: cannot find file <$server_iorfile>\n";
    $SV->Kill (); $SV->TimedWait (1);
    exit 1;
}

$client_status = $CL->SpawnWaitKill ($client->ProcessStartWaitInterval());
$server_status = $SV->WaitKill ($server->ProcessStopWaitInterval());

$server->DeleteFile($iorbase);
$client->DeleteFile($iorbase);
$server->DeleteFile($testbase); # created by the program

if ($client_status != 0) {
    print STDERR "ERROR: client returned $client_status\n";
    $status = 1;
}

if ($server_status != 0) {
    print STDERR "ERROR: server returned $server_status\n";
    $status = 1;
}

exit $status;
