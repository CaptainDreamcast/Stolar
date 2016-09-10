#define AnimateWithAnimationFactorLoop(Ticks, AnimationDurationInSeconds, AnimationFactor, CurrentFrame, FrameAmount)		AnimateWithAnimationFactor(Ticks, AnimationDurationInSeconds, AnimationFactor, CurrentFrame, FrameAmount, {})

#define AnimateWithAnimationFactor(Ticks, AnimationDurationInSeconds, AnimationFactor, CurrentFrame, FrameAmount, Action){ \
Ticks++; \
if(Ticks >= (((AnimationDurationInSeconds*AnimationFactor)*FrameRate)/FrameAmount)){ \
Ticks = 0; \
CurrentFrame++; \
if(CurrentFrame >= FrameAmount){ \
CurrentFrame = 0; \
Action; \
} \
} \
}



#define TileAnimateWithAnimationFactor(AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)		GeneralAnimateWithAnimationFactor(TileDrawResetAnimation(CurrentAnimation), AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)	

#define FightAnimateWithAnimationFactor(AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)	GeneralAnimateWithAnimationFactor(FightDrawResetAnimation(CurrentAnimation), AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)	
#define FightAnimateWithAnimationFactorManual(AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)	{ \
AnimateWithAnimationFactor(Ticks, AnimationData->AnimationDurationInSeconds, AnimationFactor, CurrentFrame, AnimationData->FrameAmount, \
{ \
FightDrawResetAnimation(CurrentAnimation); \
} \
); \
}

#define GeneralAnimateWithAnimationFactor(Action, AnimationData, Ticks, AnimationFactor, CurrentFrame, CurrentAnimation)	{ \
AnimateWithAnimationFactor(Ticks, AnimationData[CurrentAnimation].AnimationDurationInSeconds, AnimationFactor, CurrentFrame, AnimationData[CurrentAnimation].FrameAmount, \
{ \
Action; \
} \
); \
}
