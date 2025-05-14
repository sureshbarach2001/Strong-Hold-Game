# Stronghold Game Manual

## Table of Contents
1. [Introduction](#introduction)
2. [Game Overview](#game-overview)
3. [Getting Started](#getting-started)
4. [Game Mechanics](#game-mechanics)
5. [Advanced Strategies](#advanced-strategies)
6. [Troubleshooting](#troubleshooting)

## Introduction
Stronghold is a kingdom management simulation game where you control a medieval kingdom. Your goal is to build a prosperous and powerful kingdom through careful management of resources, population, military, and diplomacy.

## Game Overview

### Initial Setup
- Two kingdoms are created: Kingdom1 and Kingdom2
- Each kingdom starts with:
  - Population: 1000 (500 peasants, 300 merchants, 200 nobles)
  - Resources: 5000 food, 2000 wood, 1500 stone, 1000 iron
  - Military: 100 soldiers
  - Treasury: 1000 gold
  - Tax rate: 10%

### Game Flow
1. Each turn represents one month
2. Players take turns managing their kingdom
3. Random events can occur each turn
4. Game continues until a player exits or saves

## Getting Started

### First Turn
1. Check your kingdom's status
2. Review available resources
3. Set initial tax rates
4. Begin resource management

### Basic Commands
```
1. Set tax rate
2. Recruit soldiers
3. Send message
4. Form alliance
5. Trade
6. Attack
7. Save game
8. Exit
```

## Game Mechanics

### 1. Population Management

#### Social Classes
- **Peasants**
  - Base: 500
  - Productivity: 0.5
  - Tax contribution: Low
  - Food consumption: 1 per person
  - Strategy: Keep well-fed, low taxes

- **Merchants**
  - Base: 300
  - Productivity: 2.0
  - Tax contribution: Medium
  - Food consumption: 1 per person
  - Strategy: Moderate taxes, focus on trade

- **Nobles**
  - Base: 200
  - Productivity: 5.0
  - Tax contribution: High
  - Food consumption: 1 per person
  - Strategy: Higher taxes, military focus

#### Population Growth
- Growth rate: 10% per turn with enough food
- Starvation: -5% if food < population
- Optimal food: 150% of population

### 2. Resource Management

#### Food
- Production: Based on peasant population
- Consumption: 1 per person
- Trading value: 2 gold
- Critical threshold: Population size
- Strategy: Maintain 150% of population

#### Wood
- Initial: 2000
- Uses: Construction, trade
- Trading value: 3 gold
- Strategy: Keep minimum 1000

#### Stone
- Initial: 1500
- Uses: Fortifications, infrastructure
- Trading value: 4 gold
- Strategy: Essential for defense

#### Iron
- Initial: 1000
- Uses: Weapons, tools
- Trading value: 5 gold
- Strategy: Military priority

### 3. Military System

#### Soldiers
- Initial: 100
- Cost: 10 gold each
- Training: 1 turn
- Morale impact: +1 per 10 soldiers

#### Combat
- Strength calculation:
  - Base = soldiers × (1 + training/100)
  - Morale modifier = 1 + (morale/100)
  - Random factor: 0.8 to 1.2
- Battle outcomes:
  - Winner: -50% soldiers
  - Loser: -50% soldiers, -50% food

### 4. Economy System

#### Treasury
- Initial: 1000 gold
- Income: Population × productivity × tax rate
- Expenses: Military, resources, trade

#### Tax Rates
- Peasants: 5-10%
- Merchants: 10-15%
- Nobles: 15-20%
- Morale impact: -1 per 5% increase

### 5. Diplomatic Actions

#### Alliances
- Requirements:
  - Both kingdoms agree
  - No existing alliance
  - 1000 gold each
- Benefits:
  - Shared resources
  - Military support
  - Trade bonuses

#### Trade
- Regular trade: 1:1 exchange
- Smuggling: 1.5:1 exchange
  - 30% detection chance
  - Heavy penalties if caught

#### Messages
- Communication history
- Diplomatic negotiations
- Trade agreements

### 6. Random Events

#### Famine
- Frequency: 10% per turn
- Impact: -50% food
- Recovery: 3-5 turns

#### Disease
- Frequency: 5% per turn
- Impact: -10% population
- Recovery: 2-3 turns

#### War
- Frequency: 15% per turn
- Impact: -20% soldiers
- Recovery: 4-6 turns

## Advanced Strategies

### Early Game (Turns 1-10)
1. Focus on food production
2. Maintain low tax rates
3. Build basic military
4. Establish first alliance

### Mid Game (Turns 11-30)
1. Expand population
2. Increase tax rates
3. Strengthen military
4. Develop trade network

### Late Game (Turns 31+)
1. Dominate resources
2. Control alliances
3. Maintain stability
4. Prepare for conflicts

### Resource Management
1. Food: Always maintain surplus
2. Wood: Keep for construction
3. Stone: Reserve for defense
4. Iron: Prioritize military

### Military Strategy
1. Recruit in batches of 10
2. Maintain high morale
3. Attack when strength > 1.5× opponent
4. Plan for post-battle recovery

### Economic Strategy
1. Balance tax rates by class
2. Maintain 20% treasury reserve
3. Invest in growth
4. Plan for emergencies

### Diplomatic Strategy
1. Form early alliances
2. Choose strong partners
3. Maintain trust
4. Use trade effectively

## Troubleshooting

### Common Issues
1. "Insufficient funds"
   - Check treasury
   - Reduce spending
   - Increase taxes carefully

2. "Population starving"
   - Increase food production
   - Reduce population growth
   - Trade for food

3. "Military weak"
   - Recruit more soldiers
   - Improve training
   - Maintain high morale

4. "Alliance failed"
   - Check requirements
   - Ensure enough gold
   - Verify no existing alliance

### Game Tips
1. Save regularly
2. Monitor resources
3. Plan ahead
4. Adapt to events
5. Balance priorities

## Conclusion
Stronghold is a complex strategy game that requires careful planning and management. Success comes from balancing various aspects of your kingdom while adapting to changing circumstances. Remember to save your progress regularly and learn from each game session.

## Additional Resources
- In-game help system
- Community forums
- Strategy guides
- Tutorial videos 