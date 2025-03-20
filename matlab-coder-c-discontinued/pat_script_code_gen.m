% PAT_SCRIPT_CODE_GEN   Generate static library pat from pat.
% 
% Script generated from project 'pat.prj' on 20-Mar-2025.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('lib','ecoder',false);
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;
cfg.GenCodeOnly = true;

%% Define argument types for entry-point 'pat'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS{1}{1} = coder.typeof(0,[1800   1]);
ARGS{1}{2} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg pat -args ARGS{1}

