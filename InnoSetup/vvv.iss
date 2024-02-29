; -- vvv.iss --
; install script for vvv

#pragma option -v+
#pragma verboselevel 9

;#define Debug

#define AppName "VVV (Virtual Volumes View)"
#define ExeName "vvv.exe"
#define AppVersion "1.5"
#define FirebirdEmbeddedPath "..\FB 2.1.4 embedded"

[Setup]
AppId=VVV-fu-ku-jitsu
AppName={#AppName}
AppVerName={#AppName} version {#AppVersion}
DefaultDirName={pf}\{#AppName}
DefaultGroupName={#AppName}
UninstallDisplayIcon={app}\{#ExeName}
LicenseFile=..\linux_specific\License.txt
VersionInfoVersion={#AppVersion}
ChangesAssociations=yes
OutputDir=.
;OutputBaseFilename=VVV- + {#AppVersion} + -Setup
OutputBaseFilename=VVV-1.5-Setup
SignTool=kSign /d $qVVV (Virtual Volumes View)$q /du $qhttp://vvvapp.sourceforge.net$q $f

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}

[Files]
Source: "E:\Build folders\VVV\build\src\Release\{#ExeName}"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\fbembed.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\firebird.conf"; DestDir: "{app}"
Source: "{#FirebirdEmbeddedPath}\firebird.msg"; DestDir: "{app}"
Source: "{#FirebirdEmbeddedPath}\ib_util.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\icudt30.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\icuin30.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\icuuc30.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\Microsoft.VC80.CRT.manifest"; DestDir: "{app}"
Source: "{#FirebirdEmbeddedPath}\msvcp80.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\msvcr80.dll"; DestDir: "{app}"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\intl\fbintl.dll"; DestDir: "{app}\intl"; Flags: replacesameversion
Source: "{#FirebirdEmbeddedPath}\intl\fbintl.conf"; DestDir: "{app}\intl"
Source: "..\vvv-struct-update.fdb"; DestDir: "{app}"; Flags: overwritereadonly uninsremovereadonly; Attribs: readonly
Source: "..\VVV.fbk"; DestDir: "{app}"
Source: "..\help\en\vvv.htb"; DestDir: "{app}"
Source: "..\translations\vvv-bg.mo"; DestDir: "{app}\languages\bg"; DestName: "vvv.mo"
Source: "..\translations\vvv-zh_TW.mo"; DestDir: "{app}\languages\zh_TW"; DestName: "vvv.mo"
Source: "..\translations\vvv-cs.mo"; DestDir: "{app}\languages\cs"; DestName: "vvv.mo"
Source: "..\translations\cs\wxstd.mo"; DestDir: "{app}\languages\cs"
Source: "..\translations\vvv-de.mo"; DestDir: "{app}\languages\de"; DestName: "vvv.mo"
Source: "..\translations\de\wxstd.mo"; DestDir: "{app}\languages\de"
Source: "..\translations\vvv-es.mo"; DestDir: "{app}\languages\es"; DestName: "vvv.mo"
Source: "..\translations\es\wxstd.mo"; DestDir: "{app}\languages\es"
Source: "..\translations\vvv-fr.mo"; DestDir: "{app}\languages\fr"; DestName: "vvv.mo"
Source: "..\translations\fr\wxstd.mo"; DestDir: "{app}\languages\fr"
Source: "..\translations\vvv-hr.mo"; DestDir: "{app}\languages\hr"; DestName: "vvv.mo"
Source: "..\translations\vvv-hu.mo"; DestDir: "{app}\languages\hu"; DestName: "vvv.mo"
Source: "..\translations\hu\wxstd.mo"; DestDir: "{app}\languages\hu"
Source: "..\translations\vvv-it.mo"; DestDir: "{app}\languages\it"; DestName: "vvv.mo"
Source: "..\translations\it\wxstd.mo"; DestDir: "{app}\languages\it"
Source: "..\translations\vvv-ja.mo"; DestDir: "{app}\languages\ja"; DestName: "vvv.mo"
Source: "..\translations\ja\wxstd.mo"; DestDir: "{app}\languages\ja"
Source: "..\translations\vvv-nl.mo"; DestDir: "{app}\languages\nl"; DestName: "vvv.mo"
Source: "..\translations\nl\wxstd.mo"; DestDir: "{app}\languages\nl"
Source: "..\translations\vvv-pl.mo"; DestDir: "{app}\languages\pl"; DestName: "vvv.mo"
Source: "..\translations\pl\wxstd.mo"; DestDir: "{app}\languages\pl"
Source: "..\translations\vvv-pt.mo"; DestDir: "{app}\languages\pt"; DestName: "vvv.mo"
Source: "..\translations\pt\wxstd.mo"; DestDir: "{app}\languages\pt"
Source: "..\translations\vvv-ro.mo"; DestDir: "{app}\languages\ro"; DestName: "vvv.mo"
Source: "..\translations\vvv-ru.mo"; DestDir: "{app}\languages\ru"; DestName: "vvv.mo"
Source: "..\translations\ru\wxstd.mo"; DestDir: "{app}\languages\ru"
Source: "..\translations\vvv-sr.mo"; DestDir: "{app}\languages\sr"; DestName: "vvv.mo"
Source: "..\translations\vvv-sr@latin.mo"; DestDir: "{app}\languages\sr@latin"; DestName: "vvv.mo"
Source: "..\translations\vvv-uk.mo"; DestDir: "{app}\languages\uk"; DestName: "vvv.mo"
Source: "..\translations\uk\wxstd.mo"; DestDir: "{app}\languages\uk"

[Icons]
Name: {commonprograms}\{#AppName}; Filename: {app}\{#ExeName}
Name: {commondesktop}\{#AppName}; Filename: {app}\{#ExeName}; Tasks: desktopicon

[Registry]
Root: HKCR; Subkey: .vvv; ValueType: string; ValueName: ; ValueData: vvvapp; Flags: uninsdeletevalue
Root: HKCR; Subkey: vvvapp; ValueType: string; ValueName: ; ValueData: {#AppName}; Flags: uninsdeletekey
Root: HKCR; Subkey: vvvapp\DefaultIcon; ValueType: string; ValueName: ; ValueData: {app}\{#ExeName},0
Root: HKCR; Subkey: vvvapp\shell\open\command; ValueType: string; ValueName: ; ValueData: """{app}\{#ExeName}"" ""%1"""
Root: HKCU; Subkey: Software\VVV; Flags: uninsdeletekey

[Languages]
Name: en; MessagesFile: compiler:Default.isl
Name: it; MessagesFile: compiler:Languages\Italian.isl
Name: cs; MessagesFile: compiler:Languages\Czech.isl
Name: de; MessagesFile: compiler:Languages\German.isl
Name: es; MessagesFile: compiler:Languages\Spanish.isl
Name: fr; MessagesFile: compiler:Languages\French.isl
Name: nl; MessagesFile: compiler:Languages\Dutch.isl
Name: pl; MessagesFile: compiler:Languages\Polish.isl
Name: pt; MessagesFile: compiler:Languages\Portuguese.isl
Name: ru; MessagesFile: compiler:Languages\Russian.isl

#ifdef Debug
  #expr SaveToFile(AddBackslash(SourcePath) + "Preprocessed.iss")
#endif
