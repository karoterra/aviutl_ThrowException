$gitTag = (git tag --points-at)
$archiveName = "aviutl_ThrowException"
if (![string]::IsNullOrEmpty($gitTag))
{
    $archiveName = "${archiveName}_${gitTag}"
}

New-Item publish -ItemType Directory -Force

7z a "publish\${archiveName}.zip" `
    .\README.md `
    .\CHANGELOG.md `
    .\LICENSE `
    .\CREDITS.md `
    ".\build\Release\ThrowException.auf"
