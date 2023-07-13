// Shootka Game. All rights reserved!

using UnrealBuildTool;

public class Shootka : ModuleRules
{
	public Shootka(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Niagara",
			"PhysicsCore",
			"GameplayTasks",
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] 
			{"Shootka/Public/Player",
			"Shootka/Public/Components",
			"Shootka/Public/dev",
            "Shootka/Public/Weapon",
            "Shootka/Public/UI",
            "Shootka/Public/Animations",
            "Shootka/Public/Pickups",
            "Shootka/Public/Weapon/Components",
            "Shootka/Public/AI",
            "Shootka/Public/AI/Tasks",
            "Shootka/Public/AI/Services",
			"Shootka/Public/AI/EQS",
            "Shootka/Public/AI/Decorators",
            "Shootka/Public/Menu",
            "Shootka/Public/Menu/UI",
            "Shootka/Public/Sound"
            }
		);;
		 
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		       
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
