# Same checks as ./Grade (bash). Run from Lab07 after building a.exe.
$ErrorActionPreference = "Stop"
Set-Location $PSScriptRoot

if (-not (Test-Path ".\a.exe")) {
    Write-Host "Build first: g++ -std=c++11 -o a.exe aaravsharma.cpp"
    exit 1
}

if (-not (Test-Path ".\testfiles\t1")) {
    Write-Host "Missing testfiles. Unzip lab07.zip here so testfiles\t1..t5 and o1..o5 exist."
    exit 1
}

if (Test-Path ".\result") { Remove-Item ".\result" }
$j = 0

function Normalize-Lines($lines) {
    foreach ($line in $lines) { $line.TrimEnd("`r") }
}

for ($i = 1; $i -le 5; $i++) {
    $tin = ".\testfiles\t$i"
    $oout = ".\testfiles\o$i"
    $student = @(Normalize-Lines (Get-Content $tin | & ".\a.exe"))
    $expected = @(Normalize-Lines (Get-Content $oout))
    $diff = Compare-Object $student $expected
    if ($diff) {
        Write-Host "  !!Incorrect for $i th example."
    } else {
        Write-Host "  Correct for $i th example."
        $j++
    }
    "==================" | Add-Content ".\result"
    "test $i :" | Add-Content ".\result"
    "student:" | Add-Content ".\result"
    $student | Add-Content ".\result"
    "" | Add-Content ".\result"
    "grader:" | Add-Content ".\result"
    $expected | Add-Content ".\result"
    "" | Add-Content ".\result"
}

Write-Host " $j / 5"
